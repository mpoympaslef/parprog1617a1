


#include <stdio.h>
	#include <stdlib.h>
	#include <sys/time.h>
	
	#define R 1
	#define N 60
	#define M 120
	
	//sinartisi gia ti metrisi xronou
	void get_walltime(double *wct)//diktis wct
	{
		struct timeval tp;
		gettimeofday(&tp,NULL);
		*wct=(double)(tp.tv_sec+tp.tv_usec/1000000.0);
	}
	
	int main()
	{
	float *x,*z;
	int i,j;
	double start_time,ending_time,mflops;//start_time: xronos ekinisis ending_time:xronos termatismou
	const float K0=0.5, K1=0.5, K2=0.5, K3=0.5, K4=5.0, K5=0.5, K6=0.5, K7=0.5, K8=0.5;
	
	//allocate tous pinakes kai check
	x = (float *)malloc(N*M*sizeof(float));
	if (x==NULL) exit(1);
	z = (float *)malloc(N*M*sizeof(float));
	if (z==NULL)
	{
		free(x);
		exit(1);
	}
	
	//arxikopoiisi pinakon
	
	for (i=0;i<N*M;i++)
	{
		x[i]=0.0; z[i]=0.0;
		
	}
	
	for (i=1;i<N-1;i++)		
	{
		for (j=1;j<M-1;j++)
		{
			*(x+((i*M)+j))=rand()+0.0;//tixaies float times
		}
	
	}
	
	/*for (i=0;i<N*M;i++)//eksagogi (gia elegxo)
	{
		printf("%d ",i+1);
		printf("%f\n",x[i]);
		
	}*/
		
	get_walltime(&start_time);// lipsi xronou ekkinisis 
	
	//load code
	for (i=1;i<N-1;i++)//elegxos tou image input me ti xrisi tou i kai j ektos tou anoterou kai katoterou oriou	
			
	{
		for (j=1;j<M-1;j++)
		{
			[i*M+j]=K0*x[(i-1)*M+(j-1)]+K1*x[(i-1)*M+j]+K2*x[(i-1)*M+(j+1)]+K3*x[i*M+(j-1)]+K4*x[i*M+j]+K5*x[i*M+(j+1)]+K6*x[(i+1)*M+(j-1)]+K7*x[(i+1)*M+j]+K8*x[(i+1)*M+(j+1)];
			
		}
	}
	
	get_walltime(&ending_time);//lipsi xronou termatismou
	
	/*for (i=0;i<N*M;i++) //ektiposi tou output image (gia elegxo)
	{
		printf("%d ",i+1);
		printf("%f\n",z[i]);
	}*/
	  
	//ypologismos ton mflops
	mflops = (M*R*2.0)/((ending_time-start_time)*1e6);
	printf("MFLOPS/sec = %f\n",mflops);
	  
	// apeleytherosi mnimis
	free(x);
	free(z);
	
	return 0;
	}

