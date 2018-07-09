#include<iostream>
#include<algorithm>
using namespace std;

class Triplet{
  public:
    long long int gcd;
  	long long int x;
  	long long int y;
};

Triplet extendedEuclid(long long int a ,long long int b){
  	
  	//base case
  	if(b==0){
      	Triplet myans;
      	myans.gcd=a;
      	myans.x=1;
      	myans.y=0;
    	return myans;
    }
  
  	//Extended euclid algorithm
  	Triplet smallans = extendedEuclid(b,a%b);
  	Triplet myans;
  	myans.x=smallans.y;
  	myans.y=(smallans.x-((a/b)*smallans.y));
  	
  	return myans;
}


long long int modInverse(long long int a,long long int b){
  	Triplet myans = extendedEuclid(a,b);
  	long long int ans = (myans.x%b + b)%b;
  	return ans;
}


long long int computeMinValue(long long int a,long long int b,long long int d){
  	long long int smallOutput1=(d)%a;
  	long long int smallOutput2=modInverse(b,a);
  	
  	long long int ans=(smallOutput1 *smallOutput2)%a;
  	return ans;
}



int main(){
	// Write your code here
  	long long int t;
  	cin>>t;
  	while(t--){
  		long long int a,b,d;
  		cin>>a>>b>>d;
      
      	long long int g = __gcd(a,b);
      //special cases
      	if(d%g){
          	cout<<0<<endl;
          	continue;
        }
      	else if(d==0){
          	cout<<1<<endl;
          	continue;
        }
      
      	a/=g;
      	b/=g;
      	d/=g;
      
     	long long int y1 = computeMinValue(a,b,d);
      		
      	long long int n = (((d/b) - y1)/a)+1;
      	cout<<n<<endl;
    }

	return 0;
}
