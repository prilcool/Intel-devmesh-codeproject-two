# Intel-devmesh-codeproject-two
We  Implement  two  Statistical Mathematical Algorithms such as Pearson’s Correlation Coefficient &amp; Linear Regression  with DPC++  and  show you how to implement this algorithms in real life in sales and marketing  to  forecast Future sales based on advertising expenditure.

## Usage instructions :
Copy the entire structure including all files to  Intel dev cloud .

Ensure that the  Python 3.7 (Intel OneApi)  kernal is running

Ensure that you are using the q file ,regression.sh and Makefile that is provided with this sourcecode.

Ensure that file exist in  lab/regression.cpp


Run the following  jupyter notebook  Interest-on-account-audit-onemillion_records.ipynb

## Than Run  the following command
     ! chmod 755 q; chmod 755 regression.sh;if [ -x "$(command -v qsub)" ]; then ./q regression.sh; else ./regression.sh; fi 

## Cross architecture compatibility GPU & CPU
     This code can Run on both on CPU and GPU of below specs
     
     if you select a GPU device than Device: Intel(R) Graphics Gen9 [0x3e96] will process in 1 second.
     queue q(gpu_selector{});
    
    if you select a CPU device than Device: Intel(R) Xeon(R) E-2176G CPU @ 3.70GHz will process in 3 seconds.
     queue q(=cpu_selector{});


On successfull run :
You should be able to download the file containing the out put from the left hand side in jupyter notebook  named  regression.txt 
containing the regression analysis and working data along with the coefficients.

![alt text](https://github.com/prilcool/Intel-devmesh-codeproject-two/blob/main/Assets/out.PNG)



## Result
You can see the The Pearsons correlation is 0.529809  
You can see prediction that  Using the formula y=a+(b*50) We forcast that spending $50 on advertising can result in $84.4028 in sales
You can see the workings.
![alt text](https://github.com/prilcool/Intel-devmesh-codeproject-two/blob/main/Assets/result.PNG)
