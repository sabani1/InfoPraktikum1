#include <iostream>


int fibonacci(int zahl)
{

	if(zahl==0){
		return 0;
	}

	else if(zahl == 1){
		return 1;
	}

	else{
		return fibonacci(zahl-1)+fibonacci(zahl-2);
	}
}

int main(){

	for(int i=0; i<=25; i++){
		std::cout<<fibonacci(i)<<" "<<std::endl;
	}

	return 0;
}
