#include<bits/stdc++.h>
#include<dos.h>
#include<windows.h>
using namespace std;
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
 }
void ClearConsoleToColors(int ForgC, int BackC)
{
 WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
               //Get the handle to the current output buffer...
 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                     //This is used to reset the carat/cursor to the top left.
 COORD coord = {0, 0};
                  //A return value... indicating how many chars were written
                    //   not used but we need to capture this since it will be
                      //   written anyway (passing NULL causes an access violation).
  DWORD count;

                               //This is a structure containing all of the console info
                      // it is used here to find the size of the console.
 CONSOLE_SCREEN_BUFFER_INFO csbi;
                 //Here we will set the current color
 SetConsoleTextAttribute(hStdOut, wColor);
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                          //This fills the buffer with a given character (in this case 32=space).
      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

      FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                          //This will set our cursor position for the next print statement.
      SetConsoleCursorPosition(hStdOut, coord);
 }
 return;
}

void preKMP(string pattern, int f[])
{
    int m = pattern.length(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}

//check whether target string contains pattern
bool KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    int f[m];
    preKMP(pattern, f);
    int i = 0;
    int k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return 1;
        }
        else
            k = f[k];
    }
    return 0;
}
char ch[3][3]={{'a','n','t'}, {'z','w','e'},{'t','o','p'}};
char ch1[3][3] = {{'b','d','z'},{'e','o','o'},{'e','g','o'}};
char ch2[3][3] = {{'q','c','r'},{'f','o','x'},{'z','p','o'}};
char ch3[4][4] = {{'l','o','g','j'},{'p','u','b','i'},{'e','a','r','n'},{'a','p','e','x'}};
char ch4[4][4] = {{'p','i','e','r'},{'n','u','t','j'},{'u','r','a','t'},{'n','n','f','o'}};
char ch5[4][4] = {{'b','a','g','e'},{'a','z','a','y'},{'l','u','t','e'},{'z','c','e','y'}};
char ch6[5][5] = {{'a','o','w','r','t'},{'l','y','e','s','w'},{'l','o','e','u','o'},{'s','u','k','n','v'},{'c','e','x','a','m'}};
char ch7[5][5] = {{'o','n','e','c','b'},{'y','o','a','f','i'},{'x','t','n','m','g'},{'r','b','d','y','a'},{'c','a','n','v','s'}};
char ch8[5][5] = {{'o','t','h','e','r'},{'b','a','n','d','a'},{'i','m','u','c','n'},{'g','t','s','e','e'},{'t','r','a','c','e'}};
char ch9[6][6] = {{'c','o','y','m','s','u'},{'a','t','o','y','i','p'},{'n','i','s','o','l','o'},{'g','i','m','u','o','t'},{'o','s','e','e','o','h'},{'n','o','l','i','k','e'}};
char ch10[6][6] = {{'w','a','r','p','z','d'},{'i','j','a','m','p','m'},{'n','b','g','b','o','a'},{'k','p','e','a','l','l'},{'x','o','c','h','o','p'},{'l','o','o','p','l','q'}};
char dict[][100] = {{'a','n','t'},{'p','e','t'},{'t','o','p'},{'b','e','e'},{'d','o','g'},{'z','o','o'},{'e','g','o'},{'f','o','x'},{'c','o','p'},{'l','o','g'},{'p','u','b'},{'e','a','r','n'},{'a','p','e','x'},{'a','p','e'},{'e','a','r'},{'j','i','n','x'},{'p','i','e','r'},{'n','u','t'},{'u','r','n'},{'r','a','t'},{'f','a','t'},{'a','t','e'},{'f','a','t','e'},{'b','a','g'},{'a','g','e'},{'t','a','g'},{'g','a','t','e'},{'l','u','t','e'},{'a','t','e'},{'a','l','l'},{'e','x','a','m'},{'y','o','u'},{'t','w','o'},{'y','e','s'},{'w','e','e','k'},{'s','u','n'},{'a','n','d'},{'b','i','g'},{'n','o','t'},{'c','a','n'},{'o','n','e'},{'g','a','s'},{'t','r','a','c','e'},{'b','i','g'},{'s','e','e'},{'r','a','n'},{'a','n','d'},{'t','h','e'},{'o','t','h','e','r'},{'b','a','n'},{'b','a','n','d'},{'r','a','c','e'},{'a','c','e'},{'m','a','t'},{'s','u','n'},{'t','h','e'},{'l','i','k','e'},{'s','e','e'},{'c','a','n'},{'l','o','o','k'},{'y','o','u'},{'t','o','y'},{'p','o','t'},{'s','o','l','o'},{'w','a','r','p'},{'w','i','n','k'},{'b','o','a'},{'p','o','l','o'},{'c','h','o','p'},{'l','o','o','p'},{'j','a','m'},{'r','a','g','e'},{'a','g','e'},{'w','a','r'}};
int main()
{
    string s7 = "......";
    ClearConsoleToColors(0,15);

vector<string> arr;
for(int i=0;i<74;i++)
{

    arr.push_back(dict[i]);
    //cout<<arr[i]<<" ";

}


int a;
cout<<"\t\t\t";
string q ="WELCOME TO CROXWORD";
for(int i=0;i<q.size();i++)
    {
        cout<<q[i];
        delay(120);

    }
    cout<<endl;
    cout<<endl; SetColor(1);
cout<<"\nRULES \n\nYou will be evaluated according to size of your word.\nScore is length of the word you get correct. -1 for the wrong guess you make.\n";
delay(8000);
do{     system("cls"); SetColor(4);
        cout<<"\n\nChoose your matrix size";
cout<<"\n1. 3 X 3 \n2. 4 X 4 \n3. 5 X 5 \n4. 6 X 6 \n5. EXIT\n";
cin>>a;
switch(a)
{
    case 1 : {
        system("cls");
        srand(time(NULL));
        int r = rand()%3;

        if(r==0)
            {
                vector<string> arr2;
                cout<<"\nYOUR CROSSWORD IS : \n";
                cout<<endl;
                cout<<"\t\t"<<endl;
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        cout<<ch[i][j]<<"  ";


                    }
                    cout<<endl<<endl;

                }
                cout<<endl;
                cout<<endl;
                int b;
                cout<<"Enter the number of choices you want to make : ";
                cin>>b;
                vector<string> arr4;
                for(int i=0;i<b;i++)
                {

                    cout<<"Enter your choice "<<i+1<<": ";
                    string s3;
                    getline(cin>>ws,s3);
                    arr4.push_back(s3);


                }
               for(int i=0;i<3;i++)
                {
                    string s2(3,'\0');
                    for(int j=0;j<3;j++)
                    {

                        s2[j]=ch[i][j];

                    }
                    arr2.push_back(s2);


                }

                for(int i=0;i<3;i++)
                {
                    string s2(3,'\0');
                    for(int j=0;j<3;j++)
                    {

                        s2[j]=ch[j][i];

                    }
                    arr2.push_back(s2);


                }
                int count=0,count1=0;
                vector<string> arr6;
                vector<string> arr7;

                for(int i=0;i<b;i++)
                { int flag=0;
                    for(int j=0;j<arr2.size();j++)
                    {

                        if(KMP(arr4[i],arr2[j]))
                            {count++;
                            //cout<<"hi"<<" ";
                             flag=1;
                             break;}

                    }
                    if(flag==1)
                        count1++;


                }
                cout<<"\nYOUR PARTIALLY CORRECT ENTRIES ARE : "<<count<<endl<<endl;
                int count2=0,count3=0;
                cout<<"NOW CHECKING DICTIONARY";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                for(int p=0;p<arr4.size();p++)
                { int flag=0;
                //cout<<arr2[p]<<" ";
                    for(int g=0;g<arr.size();g++)
                    {
                        if(arr[g]==arr4[p])
                        {
                            //cout<<"hi"<<endl;
                            count2++;
                            flag=1;
                            arr6.push_back(arr[g]);

                            break;

                        }



                    }
                    if(flag==0)
                        {
                            arr7.push_back(arr4[p]);
                            count3++;

                        }


                }
                SetColor(10);
                cout<<"YOUR FULL CORRECT ENTRIES ARE : ";
                int sum=0;
                for(int i=0;i<arr6.size();i++)
                {
                    cout<<arr6[i]<<" ";
                    sum+=arr6[i].size();

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count2<<endl;
                SetColor(12);
                cout<<"YOUR WRONG ENTRIES ARE : ";

                for(int i=0;i<arr7.size();i++)
                {
                    cout<<arr7[i]<<" ";

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count3<<endl;
                SetColor(1);

                cout<<endl;
                cout<<"YOUR TOTAL SCORE IS : " ;
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                cout<<sum-count3<<" ";




            }
            if(r==1)

            {
                vector<string> arr2;
                cout<<"\nYOUR CROSSWORD IS : \n";
                cout<<endl;
                cout<<"\t\t"<<endl;
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        cout<<ch1[i][j]<<"  ";


                    }
                    cout<<endl<<endl;

                }
                cout<<endl;
                cout<<endl;
                int b;
                cout<<"Enter the number of choices you want to make : ";
                cin>>b;
                vector<string> arr4;
                for(int i=0;i<b;i++)
                {

                    cout<<"Enter your choice "<<i+1<<": ";
                    string s3;
                    getline(cin>>ws,s3);
                    arr4.push_back(s3);


                }
               for(int i=0;i<3;i++)
                {
                    string s2(3,'\0');
                    for(int j=0;j<3;j++)
                    {

                        s2[j]=ch1[i][j];

                    }
                    arr2.push_back(s2);


                }

                for(int i=0;i<3;i++)
                {
                    string s2(3,'\0');
                    for(int j=0;j<3;j++)
                    {

                        s2[j]=ch1[j][i];

                    }
                    arr2.push_back(s2);


                }
                int count=0,count1=0;
                vector<string> arr6;
                vector<string> arr7;

                for(int i=0;i<b;i++)
                { int flag=0;
                    for(int j=0;j<arr2.size();j++)
                    {

                        if(KMP(arr4[i],arr2[j]))
                            {count++;
                            //cout<<"hi"<<" ";
                             flag=1;
                             break;}

                    }
                    if(flag==1)
                        count1++;


                }
                cout<<"\nYOUR PARTIALLY CORRECT ENTRIES ARE : "<<count<<endl<<endl;
                int count2=0,count3=0;
                cout<<"NOW CHECKING DICTIONARY";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                for(int p=0;p<arr4.size();p++)
                { int flag=0;
                //cout<<arr2[p]<<" ";
                    for(int g=0;g<arr.size();g++)
                    {
                        if(arr[g]==arr4[p])
                        {
                            //cout<<"hi"<<endl;
                            count2++;
                            flag=1;
                            arr6.push_back(arr[g]);

                            break;

                        }



                    }
                    if(flag==0)
                        {
                            arr7.push_back(arr4[p]);
                            count3++;

                        }


                }
                SetColor(10);
                cout<<"YOUR FULL CORRECT ENTRIES ARE : ";
                int sum=0;
                for(int i=0;i<arr6.size();i++)
                {
                    cout<<arr6[i]<<" ";
                    sum+=arr6[i].size();

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count2<<endl;
                SetColor(12);
                cout<<"YOUR WRONG ENTRIES ARE : ";

                for(int i=0;i<arr7.size();i++)
                {
                    cout<<arr7[i]<<" ";

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count3<<endl;
                SetColor(1);

                cout<<endl;
                cout<<"YOUR TOTAL SCORE IS : " ;
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                cout<<sum-count3<<" ";




            }
            if(r==2)
            {
                vector<string> arr2;
                cout<<"\nYOUR CROSSWORD IS : \n";
                cout<<endl;
                cout<<"\t\t"<<endl;
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        cout<<ch2[i][j]<<"  ";


                    }
                    cout<<endl<<endl;

                }
                cout<<endl;
                cout<<endl;
                int b;
                cout<<"Enter the number of choices you want to make : ";
                cin>>b;
                vector<string> arr4;
                for(int i=0;i<b;i++)
                {

                    cout<<"Enter your choice "<<i+1<<": ";
                    string s3;
                    getline(cin>>ws,s3);
                    arr4.push_back(s3);


                }
               for(int i=0;i<3;i++)
                {
                    string s2(3,'\0');
                    for(int j=0;j<3;j++)
                    {

                        s2[j]=ch2[i][j];

                    }
                    arr2.push_back(s2);


                }

                for(int i=0;i<3;i++)
                {
                    string s2(3,'\0');
                    for(int j=0;j<3;j++)
                    {

                        s2[j]=ch2[j][i];

                    }
                    arr2.push_back(s2);


                }
                int count=0,count1=0;
                vector<string> arr6;
                vector<string> arr7;

                for(int i=0;i<b;i++)
                { int flag=0;
                    for(int j=0;j<arr2.size();j++)
                    {

                        if(KMP(arr4[i],arr2[j]))
                            {count++;
                            //cout<<"hi"<<" ";
                             flag=1;
                             break;}

                    }
                    if(flag==1)
                        count1++;


                }
                cout<<"\nYOUR PARTIALLY CORRECT ENTRIES ARE : "<<count<<endl<<endl;
                int count2=0,count3=0;
                cout<<"NOW CHECKING DICTIONARY";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                for(int p=0;p<arr4.size();p++)
                { int flag=0;
                //cout<<arr2[p]<<" ";
                    for(int g=0;g<arr.size();g++)
                    {
                        if(arr[g]==arr4[p])
                        {
                            //cout<<"hi"<<endl;
                            count2++;
                            flag=1;
                            arr6.push_back(arr[g]);

                            break;

                        }



                    }
                    if(flag==0)
                        {
                            arr7.push_back(arr4[p]);
                            count3++;

                        }


                }
                SetColor(10);
                cout<<"YOUR FULL CORRECT ENTRIES ARE : ";
                int sum=0;
                for(int i=0;i<arr6.size();i++)
                {
                    cout<<arr6[i]<<" ";
                    sum+=arr6[i].size();

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count2<<endl;
                SetColor(12);
                cout<<"YOUR WRONG ENTRIES ARE : ";

                for(int i=0;i<arr7.size();i++)
                {
                    cout<<arr7[i]<<" ";

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count3<<endl;

                cout<<endl;
                SetColor(1);
                cout<<"YOUR TOTAL SCORE IS : ";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                cout<<sum-count3<<" ";




            }
            delay(5000);
            break;
        }
        case 2: {
            system("cls");
            srand(time(NULL));
        int r = rand()%3;

        if(r==0)
            {
                vector<string> arr2;
                cout<<"\nYOUR CROSSWORD IS : \n";
                cout<<endl;
                cout<<"\t\t"<<endl;
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        cout<<ch3[i][j]<<"  ";


                    }
                    cout<<endl<<endl;

                }
                cout<<endl;
                cout<<endl;
                int b;
                cout<<"Enter the number of choices you want to make : ";
                cin>>b;
                vector<string> arr4;
                for(int i=0;i<b;i++)
                {

                    cout<<"Enter your choice "<<i+1<<": ";
                    string s3;
                    getline(cin>>ws,s3);
                    arr4.push_back(s3);


                }
               for(int i=0;i<4;i++)
                {
                    string s2(4,'\0');
                    for(int j=0;j<4;j++)
                    {

                        s2[j]=ch3[i][j];

                    }
                    arr2.push_back(s2);


                }

                for(int i=0;i<4;i++)
                {
                    string s2(4,'\0');
                    for(int j=0;j<4;j++)
                    {

                        s2[j]=ch3[j][i];

                    }
                    arr2.push_back(s2);


                }
                int count=0,count1=0;
                vector<string> arr6;
                vector<string> arr7;

                for(int i=0;i<b;i++)
                { int flag=0;
                    for(int j=0;j<arr2.size();j++)
                    {

                        if(KMP(arr4[i],arr2[j]))
                            {count++;
                            //cout<<"hi"<<" ";
                             flag=1;
                             break;}

                    }
                    if(flag==1)
                        count1++;


                }
                cout<<"\nYOUR PARTIALLY CORRECT ENTRIES ARE : "<<count<<endl<<endl;
                int count2=0,count3=0;
                cout<<"NOW CHECKING DICTIONARY";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                for(int p=0;p<arr4.size();p++)
                { int flag=0;
                //cout<<arr2[p]<<" ";
                    for(int g=0;g<arr.size();g++)
                    {
                        if(arr[g]==arr4[p])
                        {
                            //cout<<"hi"<<endl;
                            count2++;
                            flag=1;
                            arr6.push_back(arr[g]);

                            break;

                        }



                    }
                    if(flag==0)
                        {
                            arr7.push_back(arr4[p]);
                            count3++;

                        }


                }
                SetColor(10);
                cout<<"YOUR FULL CORRECT ENTRIES ARE : ";
                int sum=0;
                for(int i=0;i<arr6.size();i++)
                {
                    cout<<arr6[i]<<" ";
                    sum+=arr6[i].size();

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count2<<endl;
                SetColor(12);
                cout<<"YOUR WRONG ENTRIES ARE : ";

                for(int i=0;i<arr7.size();i++)
                {
                    cout<<arr7[i]<<" ";

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count3<<endl;

                cout<<endl;
                SetColor(1);
                cout<<"YOUR TOTAL SCORE IS : " ;
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                cout<<sum-count3<<" ";





        }
        if(r==1)
            {
                vector<string> arr2;
                cout<<"\nYOUR CROSSWORD IS : \n";
                cout<<endl;
                cout<<"\t\t"<<endl;
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        cout<<ch4[i][j]<<"  ";


                    }
                    cout<<endl<<endl;

                }
                cout<<endl;
                cout<<endl;
                int b;
                cout<<"Enter the number of choices you want to make : ";
                cin>>b;
                vector<string> arr4;
                for(int i=0;i<b;i++)
                {

                    cout<<"Enter your choice "<<i+1<<": ";
                    string s3;
                    getline(cin>>ws,s3);
                    arr4.push_back(s3);


                }
               for(int i=0;i<4;i++)
                {
                    string s2(4,'\0');
                    for(int j=0;j<4;j++)
                    {

                        s2[j]=ch4[i][j];

                    }
                    arr2.push_back(s2);


                }

                for(int i=0;i<4;i++)
                {
                    string s2(4,'\0');
                    for(int j=0;j<4;j++)
                    {

                        s2[j]=ch4[j][i];

                    }
                    arr2.push_back(s2);


                }
                int count=0,count1=0;
                vector<string> arr6;
                vector<string> arr7;

                for(int i=0;i<b;i++)
                { int flag=0;
                    for(int j=0;j<arr2.size();j++)
                    {

                        if(KMP(arr4[i],arr2[j]))
                            {count++;
                            //cout<<"hi"<<" ";
                             flag=1;
                             break;}

                    }
                    if(flag==1)
                        count1++;


                }
                cout<<"\nYOUR PARTIALLY CORRECT ENTRIES ARE : "<<count<<endl<<endl;
                int count2=0,count3=0;
                cout<<"NOW CHECKING DICTIONARY";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                for(int p=0;p<arr4.size();p++)
                { int flag=0;
                //cout<<arr2[p]<<" ";
                    for(int g=0;g<arr.size();g++)
                    {
                        if(arr[g]==arr4[p])
                        {
                            //cout<<"hi"<<endl;
                            count2++;
                            flag=1;
                            arr6.push_back(arr[g]);

                            break;

                        }



                    }
                    if(flag==0)
                        {
                            arr7.push_back(arr4[p]);
                            count3++;

                        }


                }
                SetColor(10);
                cout<<"YOUR FULL CORRECT ENTRIES ARE : ";
                int sum=0;
                for(int i=0;i<arr6.size();i++)
                {
                    cout<<arr6[i]<<" ";
                    sum+=arr6[i].size();

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count2<<endl;
                SetColor(12);
                cout<<"YOUR WRONG ENTRIES ARE : ";

                for(int i=0;i<arr7.size();i++)
                {
                    cout<<arr7[i]<<" ";

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count3<<endl;

                cout<<endl;
                SetColor(1);
                cout<<"YOUR TOTAL SCORE IS : ";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                cout<<sum-count3<<" ";





        }
        if(r==2)
            {
                vector<string> arr2;
                cout<<"\nYOUR CROSSWORD IS : \n";
                cout<<endl;
                cout<<"\t\t"<<endl;
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        cout<<ch5[i][j]<<"  ";


                    }
                    cout<<endl<<endl;

                }
                cout<<endl;
                cout<<endl;
                int b;
                cout<<"Enter the number of choices you want to make : ";
                cin>>b;
                vector<string> arr4;
                for(int i=0;i<b;i++)
                {

                    cout<<"Enter your choice "<<i+1<<": ";
                    string s3;
                    getline(cin>>ws,s3);
                    arr4.push_back(s3);


                }
               for(int i=0;i<4;i++)
                {
                    string s2(4,'\0');
                    for(int j=0;j<4;j++)
                    {

                        s2[j]=ch5[i][j];

                    }
                    arr2.push_back(s2);


                }

                for(int i=0;i<4;i++)
                {
                    string s2(4,'\0');
                    for(int j=0;j<4;j++)
                    {

                        s2[j]=ch5[j][i];

                    }
                    arr2.push_back(s2);


                }
                int count=0,count1=0;
                vector<string> arr6;
                vector<string> arr7;

                for(int i=0;i<b;i++)
                { int flag=0;
                    for(int j=0;j<arr2.size();j++)
                    {

                        if(KMP(arr4[i],arr2[j]))
                            {count++;
                            //cout<<"hi"<<" ";
                             flag=1;
                             break;}

                    }
                    if(flag==1)
                        count1++;


                }
                cout<<"\nYOUR PARTIALLY CORRECT ENTRIES ARE : "<<count<<endl<<endl;
                int count2=0,count3=0;
                cout<<"NOW CHECKING DICTIONARY";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                for(int p=0;p<arr4.size();p++)
                { int flag=0;
                //cout<<arr2[p]<<" ";
                    for(int g=0;g<arr.size();g++)
                    {
                        if(arr[g]==arr4[p])
                        {
                            //cout<<"hi"<<endl;
                            count2++;
                            flag=1;
                            arr6.push_back(arr[g]);

                            break;

                        }
                    }
                    if(flag==0)
                        {
                            arr7.push_back(arr4[p]);
                            count3++;

                        }


                }
                SetColor(10);
                cout<<"YOUR FULL CORRECT ENTRIES ARE : ";
                int sum=0;
                for(int i=0;i<arr6.size();i++)
                {
                    cout<<arr6[i]<<" ";
                    sum+=arr6[i].size();

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count2<<endl;
                SetColor(12);
                cout<<"YOUR WRONG ENTRIES ARE : ";

                for(int i=0;i<arr7.size();i++)
                {
                    cout<<arr7[i]<<" ";

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count3<<endl;

                cout<<endl;
                SetColor(1);
                cout<<"YOUR TOTAL SCORE IS : " ;
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                cout<<sum-count3<<" ";

        }
        delay(5000);

        break;
        }

        case 3 :
            {
                system("cls");
                srand(time(NULL));
        int r = rand()%3;

        if(r==0)
            {
                vector<string> arr2;
                cout<<"\nYOUR CROSSWORD IS : \n";
                cout<<endl;
                cout<<"\t\t"<<endl;
                for(int i=0;i<5;i++)
                {
                    for(int j=0;j<5;j++)
                    {
                        cout<<ch6[i][j]<<"  ";


                    }
                    cout<<endl<<endl;

                }
                cout<<endl;
                cout<<endl;
                int b;
                cout<<"Enter the number of choices you want to make : ";
                cin>>b;
                vector<string> arr4;
                for(int i=0;i<b;i++)
                {

                    cout<<"Enter your choice "<<i+1<<": ";
                    string s3;
                    getline(cin>>ws,s3);
                    arr4.push_back(s3);


                }
               for(int i=0;i<5;i++)
                {
                    string s2(5,'\0');
                    for(int j=0;j<5;j++)
                    {

                        s2[j]=ch6[i][j];

                    }
                    arr2.push_back(s2);


                }

                for(int i=0;i<5;i++)
                {
                    string s2(5,'\0');
                    for(int j=0;j<5;j++)
                    {

                        s2[j]=ch6[j][i];

                    }
                    arr2.push_back(s2);


                }
                int count=0,count1=0;
                vector<string> arr6;
                vector<string> arr7;

                for(int i=0;i<b;i++)
                { int flag=0;
                    for(int j=0;j<arr2.size();j++)
                    {

                        if(KMP(arr4[i],arr2[j]))
                            {count++;
                            //cout<<"hi"<<" ";
                             flag=1;
                             break;}

                    }
                    if(flag==1)
                        count1++;


                }
                cout<<"\nYOUR PARTIALLY CORRECT ENTRIES ARE : "<<count<<endl<<endl;
                int count2=0,count3=0;
                cout<<"NOW CHECKING DICTIONARY";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                for(int p=0;p<arr4.size();p++)
                { int flag=0;
                //cout<<arr2[p]<<" ";
                    for(int g=0;g<arr.size();g++)
                    {
                        if(arr[g]==arr4[p])
                        {
                            //cout<<"hi"<<endl;
                            count2++;
                            flag=1;
                            arr6.push_back(arr[g]);

                            break;

                        }



                    }
                    if(flag==0)
                        {
                            arr7.push_back(arr4[p]);
                            count3++;

                        }


                }
                SetColor(10);
                cout<<"YOUR FULL CORRECT ENTRIES ARE : ";
                int sum=0;
                for(int i=0;i<arr6.size();i++)
                {
                    cout<<arr6[i]<<" ";
                    sum+=arr6[i].size();

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count2<<endl;
                SetColor(12);
                cout<<"YOUR WRONG ENTRIES ARE : ";

                for(int i=0;i<arr7.size();i++)
                {
                    cout<<arr7[i]<<" ";

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count3<<endl;

                cout<<endl;
                SetColor(1);
                cout<<"YOUR TOTAL SCORE IS : " ;
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                cout<<sum-count3<<" ";





        }
        if(r==1)
            {
                vector<string> arr2;
                cout<<"\nYOUR CROSSWORD IS : \n";
                cout<<endl;
                cout<<"\t\t"<<endl;
                for(int i=0;i<5;i++)
                {
                    for(int j=0;j<5;j++)
                    {
                        cout<<ch7[i][j]<<"  ";


                    }
                    cout<<endl<<endl;

                }
                cout<<endl;
                cout<<endl;
                int b;
                cout<<"Enter the number of choices you want to make : ";
                cin>>b;
                vector<string> arr4;
                for(int i=0;i<b;i++)
                {

                    cout<<"Enter your choice "<<i+1<<": ";
                    string s3;
                    getline(cin>>ws,s3);
                    arr4.push_back(s3);


                }
               for(int i=0;i<5;i++)
                {
                    string s2(5,'\0');
                    for(int j=0;j<5;j++)
                    {

                        s2[j]=ch7[i][j];

                    }
                    arr2.push_back(s2);


                }

                for(int i=0;i<5;i++)
                {
                    string s2(5,'\0');
                    for(int j=0;j<5;j++)
                    {

                        s2[j]=ch7[j][i];

                    }
                    arr2.push_back(s2);


                }
                int count=0,count1=0;
                vector<string> arr6;
                vector<string> arr7;

                for(int i=0;i<b;i++)
                { int flag=0;
                    for(int j=0;j<arr2.size();j++)
                    {

                        if(KMP(arr4[i],arr2[j]))
                            {count++;
                            //cout<<"hi"<<" ";
                             flag=1;
                             break;}

                    }
                    if(flag==1)
                        count1++;


                }
                cout<<"\nYOUR PARTIALLY CORRECT ENTRIES ARE : "<<count<<endl<<endl;
                int count2=0,count3=0;
                cout<<"NOW CHECKING DICTIONARY";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                for(int p=0;p<arr4.size();p++)
                { int flag=0;
                //cout<<arr2[p]<<" ";
                    for(int g=0;g<arr.size();g++)
                    {
                        if(arr[g]==arr4[p])
                        {
                            //cout<<"hi"<<endl;
                            count2++;
                            flag=1;
                            arr6.push_back(arr[g]);

                            break;

                        }



                    }
                    if(flag==0)
                        {
                            arr7.push_back(arr4[p]);
                            count3++;

                        }


                }
                SetColor(10);
                cout<<"YOUR FULL CORRECT ENTRIES ARE : ";
                int sum=0;
                for(int i=0;i<arr6.size();i++)
                {
                    cout<<arr6[i]<<" ";
                    sum+=arr6[i].size();

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count2<<endl;
                SetColor(12);
                cout<<"YOUR WRONG ENTRIES ARE : ";

                for(int i=0;i<arr7.size();i++)
                {
                    cout<<arr7[i]<<" ";

                }
                cout<<endl;

                cout<<"TOTAL NUMBER IS : "<<count3<<endl;

                cout<<endl;
                SetColor(1);
                cout<<"YOUR TOTAL SCORE IS : ";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                cout<<sum-count3<<" ";





        }
        if(r==2)
            {
                vector<string> arr2;
                cout<<"\nYOUR CROSSWORD IS : \n";
                cout<<endl;
                cout<<"\t\t"<<endl;
                for(int i=0;i<5;i++)
                {
                    for(int j=0;j<5;j++)
                    {
                        cout<<ch7[i][j]<<"  ";


                    }
                    cout<<endl<<endl;

                }
                cout<<endl;
                cout<<endl;
                int b;
                cout<<"Enter the number of choices you want to make : ";
                cin>>b;
                vector<string> arr4;
                for(int i=0;i<b;i++)
                {

                    cout<<"Enter your choice "<<i+1<<": ";
                    string s3;
                    getline(cin>>ws,s3);
                    arr4.push_back(s3);


                }
               for(int i=0;i<5;i++)
                {
                    string s2(5,'\0');
                    for(int j=0;j<5;j++)
                    {

                        s2[j]=ch7[i][j];

                    }
                    arr2.push_back(s2);


                }

                for(int i=0;i<5;i++)
                {
                    string s2(5,'\0');
                    for(int j=0;j<5;j++)
                    {

                        s2[j]=ch7[j][i];

                    }
                    arr2.push_back(s2);


                }
                int count=0,count1=0;
                vector<string> arr6;
                vector<string> arr7;

                for(int i=0;i<b;i++)
                { int flag=0;
                    for(int j=0;j<arr2.size();j++)
                    {

                        if(KMP(arr4[i],arr2[j]))
                            {count++;
                            //cout<<"hi"<<" ";
                             flag=1;
                             break;}

                    }
                    if(flag==1)
                        count1++;


                }
                cout<<"\nYOUR PARTIALLY CORRECT ENTRIES ARE : "<<count<<endl<<endl;
                int count2=0,count3=0;
                cout<<"NOW CHECKING DICTIONARY";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                for(int p=0;p<arr4.size();p++)
                { int flag=0;
                //cout<<arr2[p]<<" ";
                    for(int g=0;g<arr.size();g++)
                    {
                        if(arr[g]==arr4[p])
                        {
                            //cout<<"hi"<<endl;
                            count2++;
                            flag=1;
                            arr6.push_back(arr[g]);

                            break;

                        }
                    }
                    if(flag==0)
                        {
                            arr7.push_back(arr4[p]);
                            count3++;

                        }


                }
                SetColor(10);
                cout<<"YOUR FULL CORRECT ENTRIES ARE : ";
                int sum=0;
                for(int i=0;i<arr6.size();i++)
                {
                    cout<<arr6[i]<<" ";
                    sum+=arr6[i].size();

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count2<<endl;
                SetColor(12);
                cout<<"YOUR WRONG ENTRIES ARE : ";

                for(int i=0;i<arr7.size();i++)
                {
                    cout<<arr7[i]<<" ";

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count3<<endl;

                cout<<endl;
                SetColor(1);
                cout<<"YOUR TOTAL SCORE IS : ";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                cout<<sum-count3<<" ";

        }
        delay(5000);
        break;

            }
    case 4 : {
        system("cls");
        srand(time(NULL));
        int r = rand()%2;

        if(r==0)
            {
                vector<string> arr2;
                cout<<"\nYOUR CROSSWORD IS : \n";
                cout<<endl;
                cout<<"\t\t"<<endl;
                for(int i=0;i<6;i++)
                {
                    for(int j=0;j<6;j++)
                    {
                        cout<<ch9[i][j]<<"  ";


                    }
                    cout<<endl<<endl;

                }
                cout<<endl;
                cout<<endl;
                int b;
                cout<<"Enter the number of choices you want to make : ";
                cin>>b;
                vector<string> arr4;
                for(int i=0;i<b;i++)
                {

                    cout<<"Enter your choice "<<i+1<<": ";
                    string s3;
                    getline(cin>>ws,s3);
                    arr4.push_back(s3);


                }
               for(int i=0;i<6;i++)
                {
                    string s2(6,'\0');
                    for(int j=0;j<6;j++)
                    {

                        s2[j]=ch9[i][j];

                    }
                    arr2.push_back(s2);


                }

                for(int i=0;i<6;i++)
                {
                    string s2(6,'\0');
                    for(int j=0;j<6;j++)
                    {

                        s2[j]=ch9[j][i];

                    }
                    arr2.push_back(s2);


                }
                int count=0,count1=0;
                vector<string> arr6;
                vector<string> arr7;

                for(int i=0;i<b;i++)
                { int flag=0;
                    for(int j=0;j<arr2.size();j++)
                    {

                        if(KMP(arr4[i],arr2[j]))
                            {count++;
                            //cout<<"hi"<<" ";
                             flag=1;
                             break;}

                    }
                    if(flag==1)
                        count1++;


                }
                cout<<"\nYOUR PARTIALLY CORRECT ENTRIES ARE : "<<count<<endl<<endl;
                int count2=0,count3=0;
                cout<<"NOW CHECKING DICTIONARY";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                for(int p=0;p<arr4.size();p++)
                { int flag=0;
                //cout<<arr2[p]<<" ";
                    for(int g=0;g<arr.size();g++)
                    {
                        if(arr[g]==arr4[p])
                        {
                            //cout<<"hi"<<endl;
                            count2++;
                            flag=1;
                            arr6.push_back(arr[g]);

                            break;

                        }



                    }
                    if(flag==0)
                        {
                            arr7.push_back(arr4[p]);
                            count3++;

                        }


                }
                SetColor(10);
                cout<<"YOUR FULL CORRECT ENTRIES ARE : ";
                int sum=0;
                for(int i=0;i<arr6.size();i++)
                {
                    cout<<arr6[i]<<" ";
                    sum+=arr6[i].size();

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count2<<endl;
                SetColor(12);
                cout<<"YOUR WRONG ENTRIES ARE : ";

                for(int i=0;i<arr7.size();i++)
                {
                    cout<<arr7[i]<<" ";

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count3<<endl;

                cout<<endl;
                SetColor(1);
                cout<<"YOUR TOTAL SCORE IS : ";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                cout<<sum-count3<<" ";





        }
        if(r==1)
            {
                vector<string> arr2;
                cout<<"\nYOUR CROSSWORD IS : \n";
                cout<<endl;
                cout<<"\t\t"<<endl;
                for(int i=0;i<6;i++)
                {
                    for(int j=0;j<6;j++)
                    {
                        cout<<ch10[i][j]<<"  ";


                    }
                    cout<<endl<<endl;

                }
                cout<<endl;
                cout<<endl;
                int b;
                cout<<"Enter the number of choices you want to make : ";
                cin>>b;
                vector<string> arr4;
                for(int i=0;i<b;i++)
                {

                    cout<<"Enter your choice "<<i+1<<": ";
                    string s3;
                    getline(cin>>ws,s3);
                    arr4.push_back(s3);


                }
               for(int i=0;i<6;i++)
                {
                    string s2(6,'\0');
                    for(int j=0;j<6;j++)
                    {

                        s2[j]=ch10[i][j];

                    }
                    arr2.push_back(s2);


                }

                for(int i=0;i<6;i++)
                {
                    string s2(6,'\0');
                    for(int j=0;j<6;j++)
                    {

                        s2[j]=ch10[j][i];

                    }
                    arr2.push_back(s2);


                }
                int count=0,count1=0;
                vector<string> arr6;
                vector<string> arr7;

                for(int i=0;i<b;i++)
                { int flag=0;
                    for(int j=0;j<arr2.size();j++)
                    {

                        if(KMP(arr4[i],arr2[j]))
                            {count++;
                            //cout<<"hi"<<" ";
                             flag=1;
                             break;}

                    }
                    if(flag==1)
                        count1++;


                }
                cout<<"\nYOUR PARTIALLY CORRECT ENTRIES ARE : "<<count<<endl<<endl;
                int count2=0,count3=0;
                cout<<"NOW CHECKING DICTIONARY";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                for(int p=0;p<arr4.size();p++)
                { int flag=0;
                //cout<<arr2[p]<<" ";
                    for(int g=0;g<arr.size();g++)
                    {
                        if(arr[g]==arr4[p])
                        {
                            //cout<<"hi"<<endl;
                            count2++;
                            flag=1;
                            arr6.push_back(arr[g]);

                            break;

                        }



                    }
                    if(flag==0)
                        {
                            arr7.push_back(arr4[p]);
                            count3++;

                        }


                }
                SetColor(10);
                cout<<"YOUR FULL CORRECT ENTRIES ARE : ";
                int sum=0;
                for(int i=0;i<arr6.size();i++)
                {
                    cout<<arr6[i]<<" ";
                    sum+=arr6[i].size();

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count2<<endl;
                SetColor(12);
                cout<<"YOUR WRONG ENTRIES ARE : ";

                for(int i=0;i<arr7.size();i++)
                {
                    cout<<arr7[i]<<" ";

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count3<<endl;

                cout<<endl;
                SetColor(1);
                cout<<"YOUR TOTAL SCORE IS : ";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                cout<<sum-count3<<" ";





        }
        if(r==2)
            {
                vector<string> arr2;
                cout<<"\nYOUR CROSSWORD IS : \n";
                cout<<endl;
                cout<<"\t\t"<<endl;
                for(int i=0;i<5;i++)
                {
                    for(int j=0;j<5;j++)
                    {
                        cout<<ch7[i][j]<<"  ";


                    }
                    cout<<endl<<endl;

                }
                cout<<endl;
                cout<<endl;
                int b;
                cout<<"Enter the number of choices you want to make : ";
                cin>>b;
                vector<string> arr4;
                for(int i=0;i<b;i++)
                {

                    cout<<"Enter your choice "<<i+1<<": ";
                    string s3;
                    getline(cin>>ws,s3);
                    arr4.push_back(s3);


                }
               for(int i=0;i<5;i++)
                {
                    string s2(5,'\0');
                    for(int j=0;j<5;j++)
                    {

                        s2[j]=ch7[i][j];

                    }
                    arr2.push_back(s2);


                }

                for(int i=0;i<5;i++)
                {
                    string s2(5,'\0');
                    for(int j=0;j<5;j++)
                    {

                        s2[j]=ch7[j][i];

                    }
                    arr2.push_back(s2);


                }
                int count=0,count1=0;
                vector<string> arr6;
                vector<string> arr7;

                for(int i=0;i<b;i++)
                { int flag=0;
                    for(int j=0;j<arr2.size();j++)
                    {

                        if(KMP(arr4[i],arr2[j]))
                            {count++;
                            //cout<<"hi"<<" ";
                             flag=1;
                             break;}

                    }
                    if(flag==1)
                        count1++;


                }
                cout<<"\nYOUR PARTIALLY CORRECT ENTRIES ARE : "<<count<<endl<<endl;
                int count2=0,count3=0;
                cout<<"NOW CHECKING DICTIONARY";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                for(int p=0;p<arr4.size();p++)
                { int flag=0;
                //cout<<arr2[p]<<" ";
                    for(int g=0;g<arr.size();g++)
                    {
                        if(arr[g]==arr4[p])
                        {
                            //cout<<"hi"<<endl;
                            count2++;
                            flag=1;
                            arr6.push_back(arr[g]);

                            break;

                        }
                    }
                    if(flag==0)
                        {
                            arr7.push_back(arr4[p]);
                            count3++;

                        }


                }
                SetColor(10);
                cout<<"YOUR FULL CORRECT ENTRIES ARE : ";
                int sum=0;
                for(int i=0;i<arr6.size();i++)
                {
                    cout<<arr6[i]<<" ";
                    sum+=arr6[i].size();

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count2<<endl;
                SetColor(12);
                cout<<"YOUR WRONG ENTRIES ARE : ";

                for(int i=0;i<arr7.size();i++)
                {
                    cout<<arr7[i]<<" ";

                }
                cout<<endl;
                cout<<"TOTAL NUMBER IS : "<<count3<<endl;

                cout<<endl;
                SetColor(1);
                cout<<"YOUR TOTAL SCORE IS : ";
                for(int i=0;i<6;i++)
                {
                    delay(200);
                    cout<<s7[i];
                }
                cout<<endl;
                cout<<sum-count3<<" ";

        }
        delay(5000);

    break;
    }
    case 5 : exit(0);

}}while(1);

}
