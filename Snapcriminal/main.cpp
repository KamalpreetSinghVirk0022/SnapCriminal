#include<iostream>
#include<conio.h>
#include<ctype.h>
#include<direct.h>
#include<process.h>
#include<windows.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
#include <limits> 
#include <ctime>  

using namespace std;


int login();      
void mainpage();  
void date1();     
void delay();     
void callExit();  
void centerConsoleWindow();
void registerFIR();
void displayAllFIRs();

void centerConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    RECT rect;
    GetWindowRect(consoleWindow, &rect);


    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    int windowWidth = rect.right - rect.left;
    int windowHeight = rect.bottom - rect.top;

    int posX = (screenWidth - windowWidth) / 2;
    int posY = (screenHeight - windowHeight) / 2;

    
    SetWindowPos(consoleWindow, NULL, posX, posY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
}
struct date
{
  int d;
  int m;
  int y;
};



struct court
{
  char crime[20];
  char act[20];
  char cour[20];
  char state[20];
};

struct FIR {
    char crime[50];
    char crimeTime[20];
    char crimeDate[20];
    char reason[100];
    char landmark[100];
    char sho[50];
};


struct descp
{
  char colour[20];
  char face[20];
  char imark[20];
  char height[6];
  char eye_color[20];
};



struct police
{
  char station[50];
  char fir_no[10];
  date date_arrest;
};



int login() {
    ifstream credentialsFile("credentials.txt");
    string storedUsername, storedPassword;
    credentialsFile >> storedUsername >> storedPassword;
    credentialsFile.close();

    char username[30];
    char password[30];
    int true1 = 1;
    int try1 = 0; 
    int i = 0;

    do {
        system("cls");
        cout << "\n\n\n\n\n\n";
        std::cout << "\t\t\t\t ----------------------------------\n";
        std::cout << "\t\t\t\t | SNAPCRIMINAL |\n";
        std::cout << "\t\t\t\t ----------------------------------\n";
        cout << "\n\n";
        cout << "\t\t\t\t\t";
        cout << "Username : ";
        cin >> username;
        cout << "\t\t\t\t\t";
        cout << "\n";
        cout << "\t\t\t\t\t";
        cout << "Password : ";
        cin >> password;

        if (strcmp(username, storedUsername.c_str()) == 0 && strcmp(password, storedPassword.c_str()) == 0) {
            cout << "\n\n";
            cout << "\t\t\t\t";
            cout << "You are accessed to the system!\n\n";
            cout << "\t\t\t\t";
            system("pause");
            system("cls");
            true1 = 0;
            return 1;
        } else {
            system("cls");
            try1 = try1 + 1;
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            cout << "\t\t\t\t\t";
            cout << "No. of attempts remain: " << 3 - try1;
            cout << "\n\n";
            cout << "\t\t\t\t";
            system("pause");
            if (try1 >= 3) {
                cout << "\t\t\t\t\t\t";
                cout << "\n";
                cout << "\t\t\t\t";
                cout << "No permission to enter the system!\n\n";
                cout << "\t\t\t\t";
                system("pause");

                
                system("cls");
                cout << "\n\n\n\n\n\n";
                std::cout << "\t\t\t\t ----------------------------------\n";
                std::cout << "\t\t\t\t | SNAPCRIMINAL |\n";
                std::cout << "\t\t\t\t ----------------------------------\n";
                cout << "\n\n";
                cout << "\t\t\t\t\t";
                cout << "Create a new username and password:\n\n";
                cout << "\t\t\t\t\t";
                cout << "\n";
                cout << "\t\t\t\t\t";
                cout << "Username : ";
                cin >> storedUsername;
                cout << "\t\t\t\t\t";
                cout << "\n";
                cout << "\t\t\t\t\t";
                cout << "Password : ";
                cin >> storedPassword;

                
                ofstream credentialsFile("credentials.txt");
                credentialsFile << storedUsername << " " << storedPassword;
                credentialsFile.close();

                
                try1 = 0;
            }
        }
    } while (try1 < 3);
}



void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

void mainpage()
{
  int process=0;
  system("cls");
  date1();
  cout << "\n";
  	std::cout << "\t\t\t\t    ----------------------------------\n";
    std::cout << "\t\t\t\t    |             SNAPCRIMINAL         |\n";
    std::cout << "\t\t\t\t    ----------------------------------\n";
  cout <<"\n\n";
  cout <<"\t\t\t\t";
  cout <<"Prepared By    ";
  cout <<":";
  cout <<"  Gurman Singh Mavi(3826)"<<endl;
  cout<<"                                                  Kamalpreet Singh(3847)"<<endl;
  cout <<"\n\n";
  cout <<"\t\t\t\t";
;
  
  cout <<"Project based learning";
  cout <<":";
  cout <<"    SnapCriminal";
  cout <<"\n\n";
  cout <<"\t\t\t\t";
  
  cout <<"\t\t\t\t";
  system("pause");
  cout <<"\n\t\t\t\tLoading";

  for(process=0;process<25;process++)
  {
    delay(150);
    cout <<".";
  }
  
   cout << "\n\n\t\t\t\t"; cout << "1. Sign In\n";
    cout << "\t\t\t\t"; cout << "2. Register FIR\n";
    cout << "\t\t\t\t"; cout << "3. Exit\n";
    cout << "\t\t\t\t"; cout << "Choose Option:[1/2/3] : ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            login();
            break;
        case 2:
            registerFIR(); 
            break;
            
           
        case 3:
            callExit();
            break;
        default:
            cout << "\n\n\t\t\t\t"; cout << "Invalid choice. Try again.";
            system("pause");
            mainpage();
    }
}
void displayAllFIRs() {
    system("cls");
    ifstream inFile("FIR_database.txt");
    if (!inFile) {
        cerr << "Unable to open file." << endl;
        return;
    }
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
    cout << "\nPress Enter to view the next FIR or any other key to return to the main menu.";
    cin.ignore();
    if (cin.get() == '\n') {
        displayAllFIRs(); 
    } else {
        mainpage(); 
    }
}



void registerFIR() {
    system("cls");
  
    FIR fir;
    
    cout << "\nEnter details for FIR registration:\n\n";
    cout << "Crime ";
    cin.getline(fir.crime, 50); 
    cout << "\n\nCrime Time: ";
    cin.getline(fir.crimeTime, 20); 
    cout << "\n\nCrime Date: ";
    cin.getline(fir.crimeDate, 20); 
    cout << "\n\nReason: ";
    cin.getline(fir.reason, 100); 
    cout << "\n\nNearby Landmark: ";
    cin.getline(fir.landmark, 100); 
    cout << "\n\nNearby Police Station (SHO): ";
    cin.getline(fir.sho, 50); 
    
    ofstream outFile("FIR_database.txt", ios::app);
    if (!outFile) {
        cerr << "Unable to open file." << endl;
        return;
    }
    
    outFile << "Crime: " << fir.crime << endl;
    outFile << "Crime Time: " << fir.crimeTime << endl;
    outFile << "Crime Date: " << fir.crimeDate << endl;
    outFile << "Reason: " << fir.reason << endl;
    outFile << "Nearby Landmark: " << fir.landmark << endl;
    outFile << "Nearby Police Station (SHO): " << fir.sho << endl << endl;
    
    outFile.close();
    
    cout << "\n\nFIR registered successfully.\n";
    system("pause");
    
    mainpage(); 
}
void callExit()
{
  int process = 0;
  system("cls");
  cout << "\n\n\n\n\n";
  cout << "\n\tTaking You Out of The System";
  for(process=0;process<25;process++)
    {
      delay(150);
      cout <<".";
    }
  system("cls");
  cout <<"\n\n\n\n\n\n\n\n\n\n\n";
  cout <<"\t\t\t\t\t";
  cout <<"You are out of the System.\n";
  cout <<"\t\t\t\t\t\t";
  cout << "Thank You !";
  cout <<"\n\n";
  cout <<"\t\t\t\t\t";
  system("pause");
  exit(0);
}

void date1()
{
  time_t T= time(NULL);
  struct  tm tm = *localtime(&T);
  cout << "\n\n\n";
  cout << "\t\t\t\t\t   Date:" << tm.tm_mday << "/" << tm.tm_mon+1  << "/" << tm.tm_year+1900 << "\n";
}



class criminal
{
private:
  char name[20];
  char sex[3];
  char conno[10];
  char age[4];
  char address[50];
  court COURT;
  police POLICE;
  descp des;
  public:
  int ncheck(char arr[]);                 
  int s_check(char a[]);                  
  void input(void);                       
  void output(void);                      
  void delete_rec(char con_no[]);         
  int dcheck(char n[]);                   
  void display();                         
  void remove();                         
  void modify();                          
  void list();                           
  void empty();                          

  int concheck(const char b[]);             

};


void menu(criminal l)
{
  int input;
  while(true)
  {
    system("cls");
    cout << "\n\n\n";
    cout << "\t\t\t\t\t";
    cout << "\n";
    std::cout << "\t\t\t\t    ----------------------------------\n";
    std::cout << "\t\t\t\t    |             SNAPCRIMINAL         |\n";
    std::cout << "\t\t\t\t    ----------------------------------\n";
    cout << "\n\n\n\n";
    cout << "\t\t\t\t";
    cout << " 1. ADD RECORD\n\n";
    cout << "\t\t\t\t";
    cout << " 2. MODIFY RECORD\n\n" ;
    cout << "\t\t\t\t" ;
    cout << " 3. DISPLAY RECORD\n\n" ;
    cout << "\t\t\t\t" ;
    cout << " 4. DELETE RECORD\n\n" ;
    cout << "\t\t\t\t" ;
    cout << " 5. LIST ALL RECORDS\n\n" ;
    cout << "\t\t\t\t" ;
    cout << " 6. View FIR\n\n" ;
    cout << "\t\t\t\t" ;
    cout << " 7. EXIT\n\n" ;
    cout << "\t\t\t\t" ;
    cout << "Choose Option:[1/2/3/4/5/6] : " ;
    fflush(stdin);
    cin >> input;
    switch(input)
    {
      case 1:
      {
        l.input();
        break;
      }
      case 2 :
      {
        l.modify();
        break;
      }
      case 3:
      {
        l.display();
        break;
      }
      case 4:
      {
        l.remove() ;
        break;
      }
      case 5:
      {
        l.list();
        break;
      }
      
      case 6: 
		displayAllFIRs(); 
		break; 
      case 7:
      {
        callExit();
      }
      break;

      default:
      {
        cout << "\n\n\n" ;
        cout << "\t\t\t\t" ;
        cout << "      Invalid input!" ;
        cout << "\n\n" ;
        cout << "\t\t\t\t" ;
        fflush(stdin);
        getchar();
        menu(l);
      }
    }
  }
}



int criminal::ncheck (char arr[])
{
  int i=0;
  while (arr[i]!='\0')
  {
    if (((arr[i] > 64) && (arr[i] < 92)) || ((arr[i] > 95) && (arr[i] < 124)) || (arr[i] ==' '))
    {

      i++;
      continue;
    }
    else
    {
      cout << "\n\tIncorrect input. Try again !\n ";
      return 0;
    }
  }
  return 1;
}



int criminal::s_check(char a[])
{
  if(( (a[0]=='m')||(a[0]=='f')||(a[0]=='M')||(a[0]=='F'))&&(a[1]=='\0') )
  {
    return 1;
  }
  else
  {
    cout << "\n\tIncorrect input. Try again !\n";
    return 0;
  }
}

void criminal::input() {
    system("cls");
    this->empty();
    criminal x;
    int c = 0;
    fstream filin;
    filin.open("jail.txt", ios::app);

    cout << "\n\n\n\tENTER THE CONVICT ID : ";
    cin >> this->conno;

    while (this->concheck(this->conno) == 0) {
        cout << "\tGIVEN CONVICT CODE ALREADY EXISTS! Enter a different convict ID: ";
        cin >> this->conno;
    }

    c = 0;
    cout << "\n\n    ENTER THE CONVICT DETAILS\n";
    while (c != 1) {
        cout << "\n" << setw(10) << "\tNAME    : ";
        cin.ignore(); 
        cin.getline(this->name, 60);
        c = ncheck(this->name);
    }


  fflush(stdin);
  c = 0;
  while(c != 1)
  {
    cout << "\n" << setw(10) << "\tSEX     : ";
    cin>>(this->sex);
    c = s_check(this->sex);
  }
  fflush(stdin);
  cout << "\n" << setw(10) << "\tADDRESS : ";
 cin.getline(this->address, 50);
  fflush(stdin);
  cout << "\n" << setw(10) << "\tAGE     : ";
  cin >> (this->age);

  cout <<"\n\n   ENTER THE COURT DETAILS\n";
  fflush(stdin);
  c = 0 ;
  while(c != 1)
  {
    cout <<"\n\n\tCOURT OF CONVICTION : ";
   cin.getline(this->COURT.cour, 50);
    c = ncheck(this->COURT.cour);
  }
  fflush(stdin);
  c = 0;
  while(c != 1)
  {
    cout << "\n\tSTATE : ";
     cin.getline(this->COURT.state, 50);
    c = ncheck(this->COURT.state);
  }
  fflush(stdin);
  c = 0;
  while(c != 1)
  {
    cout << "\n\tCRIME : ";
    cin >> (this->COURT.crime);
    c = ncheck(this->COURT.crime);
  }
  fflush(stdin);
  cout << "\n\tACT   : ";
  cin >> (this->COURT.act);

  system("cls");

  cout << "\n    ENTER DESCRIPTION\n\n\t ";
  fflush(stdin);
  c = 0;
  while(c != 1)
  {
    cout<<"\n\tSKIN COMPLEXTION : ";
    cin.getline(this->des.colour, 20);
    c = ncheck(this->des.colour);
  }
  fflush(stdin);
  c = 0;
  while(c != 1)
  {
  cout << "\n\tFACE DESCRIPTION : ";
 cin.getline(this->des.face, 50);
  c = ncheck(this->des.face);
  }
  fflush(stdin);
  cout << "\n\tHEIGHT : ";
  cin >> (this->des.height);

  fflush(stdin);
  cout << "\n\tIDENTIFICATION MARKS : ";
   cin.getline(this->des.imark, 100);
  fflush(stdin);
  cout << "\n\tEYE COLOUR : ";
  cin >> (this->des.eye_color);

  system("cls");

  cout << "\n\n    ENTER POLICE STATION INFORMATION \n\n\t\t ";
  cout << "\n\n\n\t\t";
  fflush(stdin);
  cout << "\n\t\tPOLICE STATION : ";
   cin.getline(this->POLICE.station, 50);
  cout <<"\n\t\tFIR NO. : ";
  fflush(stdin);
  cin >> (this->POLICE.fir_no);
  cout <<"\n\t\tDATE OF ARREST(DD/MM/YYYY)\n";
  fflush(stdin);
  c = 0;
  while(!c)
  {
    cout << "\n\t\t\t\t\t Day : ";
    cin >> this->POLICE.date_arrest.d;
    if((this->POLICE.date_arrest.d>31) || (this->POLICE.date_arrest.d<1))
    {
      cout << "\n\t\tTHIS DATE DOES NOT EXIST, TRY AGAIN!!\n";
      c = 0;
    }
    else
      c = 1;
  }
  c = 0;
  fflush(stdin);
  while(!c)
  {
    cout << "\n\t\t\t\t\t Month : ";
    cin >> this->POLICE.date_arrest.m;
    if((this->POLICE.date_arrest.m>12) || (this->POLICE.date_arrest.m<1))
    {
      cout << "\n\t\tTHIS MONTH DOES NOT EXIST, TRY AGAIN!!\n";
      c = 0;
      continue;
    }
    else
      c = 1;

    if((this->POLICE.date_arrest.d==31) && ((this->POLICE.date_arrest.m==2) || (this->POLICE.date_arrest.m==4) ||( this->POLICE.date_arrest.m==6) ||( this->POLICE.date_arrest.m==9) || (this->POLICE.date_arrest.m==11)))
    {
      cout <<"\n\t\tTHIS MONTH DOES NOT HAVE 31 DAYS \n\tTRY AGAIN !!\n";
      c = 0;
    }
    else
      c = 1;
  }
  fflush(stdin);
  c = 0;

  while(!c)
  {
    cout << "\n\t\t\t\t\t Year(4 digits) : ";
    cin >> this->POLICE.date_arrest.y;
    if((this->POLICE.date_arrest.y <= 1930)||(this->POLICE.date_arrest.y>2017))
    {
      cout << "\n\t\tINCORRECT INPUT, TRY AGAIN!!\n";
      c = 0;
    }
    else
      c = 1;
  }
  char ch;
  do
  {
    cout << "\n\tDO YOU WANT TO SAVE THIS INFORMATION(Y/N) : ";
    cin >> ch;

    if(ch=='y'||ch=='Y')
    {
      cout << "\n\n\t< RECORD HAS BEEN SAVED >";
      filin.write((char*)this,sizeof(criminal));
    }
   else
    {
      if((ch!='n')&&(ch!='N'))
      {
        cout<<"\n\t\tENTER CORRECTLY \n\t\t TRY AGAIN !!\n\n";
      }
    }
  }
  while((ch!='y') && (ch!='Y') && (ch!='n') && (ch!='N'));

  filin.close();
  cout << "\n\n\t\t";
  system("pause");

}

void criminal::output()      
{
  system("cls");
  fflush(stdin);

  cout << "\n\n\t\t----------PERSONAL RECORD OF CONVICT----------";
  cout << "\n\n\tCONVICT ID           :\t";
  puts(conno);
  cout << "\n\tNAME                 :\t";
  puts(this->name);
  cout << "\n\tSEX                  :\t" << this->sex;
  cout << "\n\n\tADDRESS              :\t";
  puts(this->address);
  cout << "\n\tAGE                  :\t";
  puts(this->age);
  cout << "\n\n\n\t\t\t";
  system("pause");


  system("cls");
  cout << "\n\n\t\t----------CRIMINAL RECORD----------";
  cout << "\n\n\t\t\tCOURT INFORMATION\n\n ";
  cout << "\n\t1. COURT OF CONVICTION        :\t";
  puts(this->COURT.cour);
  cout << "\n\t2. STATE                      :\t";
  puts(this->COURT.state);
  cout << "\n\t3. CRIME                      :\t";
  puts(this->COURT.crime);
  cout << "\n\t4. ACT                        :\t";
  puts(this->COURT.act);
  cout << "\n\n\n\t\t\t";
  system("pause");
  system("cls");

  cout << "\n\n\t\t\tDESCRIPTION\n";

  cout << "\n\t1. SKIN COMPLEXTION    :\t";
  puts(this->des.colour);
  cout << "\n\t2. FACE                :\t";
  puts(this->des.face);
  cout << "\n\t3. IDENTIFICATION MARK :\t";
  puts(this->des.imark);
  cout << "\n\t4. HEIGHT              :\t";
  puts(this->des.height);
  cout << "\n\t5. EYE COLOUR          :\t";
  puts(this->des.eye_color);
  cout << "\n\n\n\t\t\t";
  system("pause");

  system("cls");

  cout << "\n\n\n\t\tPOLICE INFORMATION \n\n";
  cout << "\n\t1. POLICE STATION    :\t";
  puts(this->POLICE.station);
  cout << "\n\t2. FIR NO.           :\t";
  puts(this->POLICE.fir_no);
  cout << "\n\t3. DATE OF ARREST    :\t" << this->POLICE.date_arrest.d <<"/" << POLICE.date_arrest.m << "/"<<this->POLICE.date_arrest.y;
  cout << "\n\n\n\t\t\t";
  system("pause");
}               


void criminal::delete_rec(char con_no[]) 
{
  fstream filin;
  fflush(stdin);
  filin.open("jail.txt",ios::in|ios::ate);
  int q = filin.tellg();
  int c = q/sizeof(criminal);
  fstream temp;
  temp.open("temp.txt",ios::out);
  filin.seekg(0,ios::beg);
  for(int i=0; i<c; i++)
  {
    filin.read((char*)this,sizeof(criminal));
    if(strcmp(con_no,conno) != 0)
    temp.write((char*)this,sizeof(criminal));
  }
  filin.close();
  temp.close();
  filin.open("jail.txt",ios::out);
  temp.open("temp.txt",ios::in|ios::ate);
  int a = temp.tellg();
  int size = a/sizeof(criminal);
  temp.seekg(0,ios::beg);
  for(int k=0; k<size; k++)
  {
    temp.read((char*)this,sizeof(criminal));
    filin.write((char*)this,sizeof(criminal));
  }
  filin.close();
  temp.close();
  cout<<"\n\n\t\t< THE RECORD HAS BEEN DELETED >";
  cout <<"\n";
  fflush(stdin);
  getchar();
}

int criminal::dcheck(char n[]) 
{
  system("cls");
  fstream file;
  file.open("jail.txt",ios::in|ios::ate|ios::binary);

  int x = 0, count = 0, c;
  int q = file.tellg();
  c = q/sizeof(criminal);
  file.close();
  file.open("jail.txt",ios::in|ios::binary);
  for(int i=0;i<c;i++)
  {
    file.read((char*)this,sizeof(criminal));
    count++;
    if(strcmp(n,conno)==0)
    {
      x++;
      break;
    }
  }
  if(x==0)
  {
    cout<<"\n\n\n\n\tCONVICT NOT FOUND!! ";
    getchar();
    return 0;
  }
  else
  {
    return count;
  }
  file.close();
}

void criminal::display()    
{
	
  system("cls");
  fflush(stdin);
  char N[10];
  int rec;
  int loc;
  cout << "\n\n\n\t\tENTER THE CONVICT ID : ";
  gets(N);
  fstream file;
  rec = this->dcheck(N);
  file.open("jail.txt",ios::in|ios::binary);
  if(rec!=0)
  {
    loc = (rec-1)*sizeof(criminal);
    file.seekg(loc);
    file.read((char*)this,sizeof(criminal));
    this->output();
  }
  
file.close();
cout <<"\n";

fflush(stdin);
}

void criminal::remove()
{
  fflush(stdin);
  system("cls");
  char no[10];
  int s;
  cout << "\n\n\n\t\tENTER THE CONVICT ID : ";
  gets(no);
  s = this->dcheck(no);
  if(s!=0)
  this->delete_rec(no);
}


void criminal::modify() 
{
  system("cls");
  fflush(stdin);
  fstream file;
  char npdr[10], ncrime[10], nact[10], nstate[10], ncourt[10], nstat[10], nfir[10];
  char str[10],nprd[15],cno[10];
  int check,loc;
  criminal x;
  date D;
  fflush(stdin);
  modify_start:
  cout << "\n\tENTER CONVICT ID : ";
  gets(str);
  check = this->dcheck(str);
  if(check != 0)
  {
    file.open("jail.txt",ios::out|ios::ate);
    int d = 0;
    cout << "\n\n\t\tRECORD FOUND !\n\n";
    cout << "\n\tENTER MODIFIED DETAILS\n";
    while(d != 1)
    {
      cout << "\n\t\t\t\tCONVICT ID : ";
      cin >> cno;
      d = x.concheck(cno);
    }
    strcpy(conno,cno);

    cout << "\n\t\t\t\tCRIME      : ";
    cin >> ncrime;
    strcpy(COURT.crime,ncrime);
    cout << "\n\t\t\t\tACT   : ";
    cin >> nact;
    strcpy(COURT.act,nact);
    cout << "\n\t\t\t\tSTATE : ";
    cin >> nstate;
    strcpy(COURT.state,nstate);
    cout << "\n\t\t\t\tCOURT : ";
    cin >> ncourt;
    strcpy(COURT.cour,ncourt);
    system("cls");
    cout << "\n\t\tENTER THE  MODIFIED POLICE RECORD\n";
    cout << "\n\t\t\t\tSTATION : ";
    cin >> nstat;
    strcpy(POLICE.station,nstat);
    cout << "\n\t\t\t\tFIR NO   : ";
    cin >> nfir;
    strcpy(POLICE.fir_no,nfir);
    cout << "\n\t\t\t\tDATE OF ARREST(DD,MM,YYYY)  ";
    int c = 0;
    while(c != 1)
    {
      cout<<"\n\t\t\t\t\t Day : ";
      cin>>D.d;
      if((D.d>31)||(D.d<1))
      {
        cout << "\n\t\tTHIS DATE DOES NOT EXIST, TRY AGAIN!!\n";
        c = 0;
      }
      else
        c = 1;
    }

    c = 0;
    while(c != 1)
    {
      cout<<"\n\t\t\t\t\t Month : ";
      cin >> D.m;
      if((D.m>12)||(D.m<1))
      {
        cout << "\n\t\tTHIS MONTH DOES NOT EXIST, TRY AGAIN!!\n";
        c = 0;
        continue;
      }
      else
        c=1;

      if((D.d==31) &&((D.m==2) || (D.m==4) ||( D.m==6) ||( D.m==9) || (D.m==11)))
      {
        cout <<"\n\t\tTHIS MONTH DOES NOT HAVE 31 DAYS \n\tTRY AGAIN !!\n";
        c = 0;
      }
      else
        c = 1;
    }
    c = 0;

    while(c != 1)
    {
      cout<<"\n\t\t\t\t\t Year(in 4 digits) : ";
      cin >> D.y;
      if((D.y <= 1930)||(D.y>=2024) )
      {
        cout << "\n\t\tINCORRECT INPUT, TRY AGAIN!!\n";
        c = 0;
      }
      else
        c = 1;
    }

    POLICE.date_arrest.d=D.d;
    POLICE.date_arrest.m=D.m;
    POLICE.date_arrest.y=D.y;

    loc = (check-1)*sizeof(criminal);
    file.seekp(loc);
    file.write((char*)this,sizeof(criminal));
    file.close();
    cout <<"\n";
    fflush(stdin);
    cout << "\n\n\t\t\t < RECORD MODIFIED >";
  }

  else
  {
      cout << "\n\n\n\t\tPRESS 'Y' TO TRY AGAIN 'N' TO GO TO QUIT : ";
      char ch_m;
      cin >> ch_m;
      fflush(stdin);
      if(ch_m == 'y' || ch_m == 'Y')
      {
        system("cls");
        goto modify_start;
      }

      else
      {
        callExit();
      }
  }
}
void returnToMainPage() {
    system("cls"); 
    mainpage();    
}

void criminal::list() 
{
  system("cls");
  fflush(stdin);
  int j ;
  fstream file;
  file.open("jail.txt",ios::in|ios::ate|ios::binary);
  int q = file.tellg();
  int c = q/sizeof(criminal);
  file.seekg(0);
  cout<<"                            \n";
  cout<<"		                                 \n";
  cout<<"                                CONVICT  LIST    \n";
  cout<<"			                         \n";
  cout<<"                            \n";
  cout<<"\n================================================================================\n";
  cout<<"SR.\tNAME\t\t\tCONVICT NO.\t\t\tCRIME\n";
  cout<<"================================================================================\n";
  int i = 0;
  while(file.read((char*)this,sizeof(criminal)))
  {
    i++;
    cout << i << "       ";
    for(j=0; j<strlen(this->name); j++)
      cout << this->name[j];
    cout<<"\t\t\t    ";
    for(j=0; j<strlen(this->conno); j++)
      cout << this->conno[j];
    cout << "\t\t\t        ";
    for(j=0; j<strlen(this->COURT.crime); j++)
      cout << this->COURT.crime[j];
      cout <<"\n";
      fflush(stdin);
      getchar();
    cout << "\n--------------------------------------------------------------------------------\n";
    if((i%3)==0&&(i!=c))
    {
      system("pause");
      system("cls");
      cout << "\n================================================================================\n";
      cout << "SR.\tNAME\t\t\tCONVICT NO.\t\t\tCRIME\n";
      cout << "================================================================================\n";
    }
  }
  file.close();
  getchar();
}

void criminal::empty()
{
  int i;
  for(i=0; i<20; i++)
    name[i]=' ';
  for(i=0; i<10; i++)
    conno[i]=' ';
  for(i=0; i<3; i++)
    sex[i]=' ';
  for(i=0; i<4; i++)
    age[i]=' ';
  for(i=0; i<50; i++)
    address[i]=' ';
  for(i=0; i<20; i++)
    COURT.cour[i]=' ';
  for(i=0; i<20; i++)
    COURT.crime[i]=' ';
  for(i=0; i<20; i++)
    COURT.act[i]=' ';
  for(i=0; i<20; i++)
    COURT.state[i]=' ';
  for(i=0; i<20; i++)
    des.colour[i]=' ';
  for(i=0; i<20; i++)
    des.imark[i]=' ';
  for(i=0; i<20; i++)
    des.face[i]=' ';
  for(i=0; i<6; i++)
    des.height[i]=' ';
  for(i=0; i<15; i++)
    des.eye_color[i]=' ';
  for(i=0; i<50; i++)
    POLICE.station[i]=' ';
  for(i=0; i<10; i++)
    POLICE.fir_no[i]=' ';
  POLICE.date_arrest.m = 0;
  POLICE.date_arrest.d = 0;
  POLICE.date_arrest.y = 0;
}

int criminal::concheck(const char b[])
{
    ifstream file("jail.dat", ios::binary);

    

    int check = 0;

    while (file.read((char*)this, sizeof(criminal))) {
        if (strcmp(b, conno) == 0) {
            check = 1;
            break;
        }
    }

    file.close();

    if (check == 0) {
        return 1;  
    } else {
        return 0;  
    }
}



int main()
{	centerConsoleWindow();
	  system("color F0");
  system("cls");
  mainpage();
  criminal l;
  int x,res=1;
  res = login();
  if(res==1){
  	menu(l);
	  }}

