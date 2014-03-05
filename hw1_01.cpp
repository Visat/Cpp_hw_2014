#include<iostream>
#include<string>
using namespace std;

class ZipCode{
   public:
      ZipCode(){   // constructor : default e_zcode, d_zcode
	     setdZipcode("0000000000000000000000000");
	     seteZipcode("00000");
	     e_code = 0;
	  }

	  void seteZipcode(string code){   //指定加密碼  (x)
         e_scode = code;	
      }
      void setdZipcode(string code){   //指定解密碼 
         d_scode = code;	
      }
      
      string geteZipcode(){   //取得加密碼 (x) 
         d_scode = encrypt(e_scode);
         return d_scode;	
      }
      int getdZipcode(){     //取得解密碼 
         e_code = decrypt(d_scode);
         return e_code;
	  }
   

   private:	
      string d_scode;	
	  string e_scode;
	  int e_code;
	  
	  int decrypt(string d_scode){   // 解碼 
	     int blo1, blo2, blo3, blo4, blo5;
	     int code;
		 blo1 = block_decode(d_scode, 5);
		 blo2 = block_decode(d_scode, 10);
		 blo3 = block_decode(d_scode, 15);
		 blo4 = block_decode(d_scode, 20);
		 blo5 = block_decode(d_scode, 25);
		 code = blo1*10000 + blo2*1000 + blo3*100 + blo4*10 + blo5;
		 return code;	
	  }

      int block_decode(string d_scode, int end){
         int cnt, cnt1=4;
         int zipvalue[5] = {0,1,2,4,7};
         int temp = 0;
		 for(cnt=(end-5); cnt<end; cnt++){
		    temp += (d_scode[cnt] - '0') * zipvalue[cnt1];	
	        cnt1--;
		 }	
      	 if(temp >= 11)   temp = 0;
      	 return temp;
      }
	  
	  
	  string encrypt(string e_scode){   // 轉碼 (x)
	     int blo[5];
	     int cnt1 = 5;
	     char code_temp[25];
		 for(int cnt=0; cnt<5; cnt++){
		    blo[cnt] = e_scode[cnt] - '0';         	
		    block_encode(code_temp, blo[cnt], cnt1);
		    cnt1 +=5;
		 	}
	  	 return code_temp;
	  }
	  
	  void block_encode(char arr[], int code_part, int end){
	     int zipvalue[5] = {1,1,2,4,7};
		 char temp;
		 int cnt, cnt1=4;
		 if(code_part == 0){   // 當code=0時預設為11的zipcode 
		    arr[end-5] = '1';
			arr[end-4] = '0';
			arr[end-3] = '1';
			arr[end-2] = '0';
			arr[end-1] = '0';	
		 }
		 else{
		    for(cnt=end-5; cnt<end; cnt++){
		 	   temp = code_part / zipvalue[cnt1] + '0';
		 	   if(temp == '1')
		 	      code_part -= zipvalue[cnt1]; 
		 	   arr[cnt] = temp;
		 	   cnt1--;
		    }	
         }
	  }

}; // end class ZipCode


int main(void)
{
   ZipCode postAddress;
   string postNum;
   int zipcode;
   string zipcode_en;
   int cho;

   cout << "Please choose the function (1=>decode, 2=>encode) : ";
   cin  >> cho;
   cout << "> > > > > > > > > > >" << endl;
   
   switch(cho){
      case 1 :   // decode
         cout << "Please enter 25bits Zip Codes : ";
         cin  >> postNum;
         while(postNum.length() != 25){
            cout << "Enter error, please enter again : ";
			cin  >> postNum;	
         }
         postAddress.setdZipcode(postNum);
         zipcode = postAddress.getdZipcode();
         cout << "The codes after decode is : " << zipcode << endl;

      case 2 :   // encode
         cout << "Please enter 5bits Post Codes : ";
         cin  >> postNum;
         while(postNum.length() != 5){
            cout << "Enter error, please enter again : ";
			cin  >> postNum;	
         }
         postAddress.seteZipcode(postNum);
         zipcode_en = postAddress.geteZipcode();
         cout << "The Zip codes after encode is : " << zipcode_en << endl;
   }
   
   return 0;	
}

