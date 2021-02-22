# Intel-devmesh-codeproject-two
We  Implement  two  Statistical Mathematical Algorithms such as Pearson’s Correlation Coefficient &amp; Linear Regression  with DPC++  and  show you how to implement this algorithms in real life in sales and marketing  to  forecast Future sales based on advertising expenditure.

## Usage instructions :
Copy the entire structure including all files to  Intel dev cloud .

Ensure that the  Python 3.7 (Intel OneApi)  kernal is running

Ensure that you are using the q file ,regression.sh and Makefile that is provided with this sourcecode.

Ensure that file exist in  lab/regression.cpp


Run the following  jupyter notebook  Interest-on-account-audit-onemillion_records.ipynb

## Than Run  the following command
     ! chmod 755 q; chmod 755 simulate_rocket_launch.sh;if [ -x "$(command -v qsub)" ]; then ./q simulate_rocket_launch.sh; else ./simulate_rocket_launch.sh; fi  

## Cross architecture compatibility GPU & CPU
     This code can Run on both on CPU and GPU of below specs
     
     if you select a GPU device than Device: Intel(R) Graphics Gen9 [0x3e96] will process in 1 second.
     queue q(gpu_selector{});
    
    if you select a CPU device than Device: Intel(R) Xeon(R) E-2176G CPU @ 3.70GHz will process in 3 seconds.
     queue q(=cpu_selector{});


On successfull run :
You should be able to download to see the output on screen 

      ## u60146 is compiling your Rocket launch simulation program.
      Simulated Result for the next rocket launch :
      The rocket reaches maximum height at 31.6327 seconds , Maximum height rocket travels is 5235.06 meters  and rocket will splash down at  time  64.3878 seconds
