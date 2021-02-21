
//==============================================================
// Copyright © 2021 Intel Corporation
// Author:Prilvesh Krishna
// Email:prilcool@hotmail.com    
// Linkedin:https://www.linkedin.com/in/prilvesh-k-4349ba54/
// Date:03/02/2020        
// SPDX-License-Identifier: MIT
// =============================================================



#include<CL/sycl.hpp>
#include<array>
#include<iostream>
#include<cmath>
#include <math.h> 
#include<iomanip>
#include<limits>
#include <chrono>



using namespace sycl;

// we create a custom pow function because GPU doesnt know default pow function
double pow(double base_unit, double power_unit){
    double result=base_unit;
    int i=1;
    while(i<power_unit){
        result=result*base_unit;
        i++;
    }
    
  return result;  
}



int main() {
    auto start_time = std::chrono::high_resolution_clock::now();

    //N specifies the numbe of values in your dataset.
    
    constexpr int N=6; 
    
    // if you select a GPU device than Device: Intel(R) Graphics Gen9 [0x3e96] will process in 1 second.
     queue q(gpu_selector{});
    
    //if you select a CPU device than Device: Intel(R) Xeon(R) E-2176G CPU @ 3.70GHz will process in 3 seconds.
    //to use cpu un comment the below and comment the above.
    //queue q(cpu_selector{});
    
    std::cout << "Device: " << q.get_device().get_info<info::device::name>() << std::endl;


    // load the  x and y datasets into the two arrays 
    // you can load the data from a file but for the purpouses of this demo we place it directly so that you can play around with it
    // using the jupyter notebook and input your own x and y values for testing etc .
    
     // If you want to use alternate datasets its easy to specify like so 
     //int x[]={41,54,63,54,48,46,62,61,64,71};  // the amounts you spend on advertising each week
     //int y[]={1250,1380,1425,1425,1450,1300,1400,1510,1575,1650}; //the sales you get each week
    
     
    
     int x[]={43,21,25,42,57,59}; // the amounts you spend on advertising each week
     int y[]={99,65,79,75,87,81};//the sales you get each week
    
    int sample_forecast=50; //you want to spend $50 next week and forecast how much sales you will make.    

    // declaring your variables
    
    int sum_x=0;  //sum of x values  
    int sum_y=0;  //sum of y values  
    int sum_xy=0; //sum of xy values  
    int sum_x_squared=0; //sum of x  squared values  
    int sum_y_squared=0; //sum of y  squared values  
    
    int*xy=malloc_shared<int>(N, q); //to hold xy calculated values  
    int*x_squared=malloc_shared<int>(N, q); // to hold x_squared calculated values  
    int*y_squared=malloc_shared<int>(N, q); // to hold y_squared calculated values

    
    // We define the incrementor 
    
    for (int i =0; i < N; i++) {
        i=i;  
    }
    
    // display text oon screen
    std::cout << "Parallel data processing initialized" << std::endl;
   
    
    //we do calculation of  x*y in parallel
    
    q.parallel_for(range<1>(N), [=](id<1> i) {
       xy[i]=x[i]*y[i];
    }).wait();

    //we do calculation of  x_squared in parallel
    
    q.parallel_for(range<1>(N), [=](id<1> i) {
       x_squared[i]=pow(x[i],2);
    }).wait();

     //we do calculation of  y_squared  in parallel
    
    q.parallel_for(range<1>(N), [=](id<1> i) {
       y_squared[i]=pow(y[i],2);
    }).wait();
    
    //Next we calculate the  sum_x ,sum_y , sum_x_squared ,sum_y_squared  sum_xy

    for (int i =0; i < N; i++) {
     sum_x+=x[i];
     sum_y+=y[i];   
     sum_x_squared+=x_squared[i];
     sum_y_squared+=y_squared[i]; 
     sum_xy+=xy[i];   
    }
    
    
    //Next we calculate the  Intercept coefficient
    
     double a=((sum_y * sum_x_squared)-(sum_x * sum_xy)) / (N * (sum_x_squared)-pow(sum_x,2)); 

    //Next we calculate the  Slope coefficient 
    
     double b=(N*(sum_xy)-(sum_x * sum_y))/(N*(sum_x_squared)-pow(sum_x,2));
    
    
    
    //Now we can run a sample forcast using the sample linear regression formula  y=a+b*(x)
    
     double Sales_regression_function=a+(b*(sample_forecast));
    
    
    //we can now also do the pearsons corelation 
    //The range of the correlation coefficient is from -1 to 1. 
    //Our result is 0.5298 or 52.98%, which means the variables have a moderate positive correlation.
    
   double pearson_r=(N*(sum_xy)-(sum_x*sum_y))/sqrt((N*(sum_x_squared)-pow(sum_x,2))* (N*(sum_y_squared)-pow(sum_y,2)));

    
    
    std::cout << "Proceeding to output results to txt file "<< std::endl;  
    std::cout<<" "<<std::endl;
   
    // we write out forcast and working data to a regression.txt text file if you have alot of data  so its better  so we can save it etc.
    // create new or append to regression.txt file.
    
     std::ofstream out("regression.txt", std::ios::app);
     
     out<<" "<<std::endl;
     out<<"The Pearsons correlation is "<<pearson_r<< std::endl;
    
     out << "Using the formula y=a+(b*"<<sample_forecast<<")"<<" We forcast that spending $"<<sample_forecast<<" on advertising can result in $"
     <<Sales_regression_function<<" in sales"<< std::endl;
 
    out<<" "<<std::endl;
    
    out<<"Below is Working Data incase you want to view the data that was calculated parallely"<<std::endl;
    out<<" "<<std::endl;
    
     out<<"Number of dataset values N is "<<N<<std::endl;
     out<<"Sum of X values "<<sum_x<<std::endl;
     out<<"Sum of Y values "<<sum_y<<std::endl; 
     out<<"Sum of X squared values "<<sum_x_squared<<std::endl;
     out<<"Sum of Y squared values "<<sum_y_squared<<std::endl; 
     out<<"Sum of XY values "<<sum_xy<<std::endl;
    
     out<<" "<<std::endl;
    
    out<<"X Value,"<<" Y Value,"<<"XY,"<<"X Squared,"<<"Y Squared,"<<std::endl;
    for (int i = 0; i < N; i++) {
   
        out<< x[i] <<","<< y[i] <<","<< xy[i] << "," << x_squared[i]<< ","  << y_squared[i]<<std::fixed << std::setprecision(2)<< std::endl;
    }
    
  
    std::cout<<" "<<std::endl;
    std::cout << "Processing complete you can now refer to the regression.txt  on the left hand side in jupyter notebook" << std::endl;
     
    auto current_time = std::chrono::high_resolution_clock::now();

     std::cout << "The Processing was completed in  " << std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count() << " seconds" << std::endl;

    //release the occupied memory,if you dont release it you will have memory leaks.
    
    free(xy,q);
    free(x_squared,q);
    free(y_squared,q);
    return 0;
}







