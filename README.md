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


On successfull run :
You should be able to download the file containing the out put from the left hand side in jupyter notebook  named  regression.txt 
containing the regression analysis and working data along with the coefficients.

![alt text](https://raw.githubusercontent.com/prilcool/Intel-devmesh-codeproject-two/main/Assets/out.PNG)


