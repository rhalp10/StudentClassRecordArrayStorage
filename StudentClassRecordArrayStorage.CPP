#include<iostream.h>
#include<conio.h>
#include<string.h>
typedef char string50[51];
typedef char string08[9];
typedef struct
{
 string50 strName;
 string08 strID;
 float fQuiz[3];
 float fMacProb[2];
 float fFinalExam;
 float fRawScore;
 float fFinalGrade;
 float fAveQ, fAveMP;
}
STUDENT_RECORD;
typedef STUDENT_RECORD CLASS_RECORD[5];
#define NAME	1
#define ID	2
#define QUIZ1	3
#define QUIZ2	4
#define QUIZ3	5
#define MP1	6
#define MP2	7
#define FE	8
//initialize the content of class record to null & 0
void initialize (CLASS_RECORD c)
{
 int i, j;
 for (i=0;i<5;i++)
  {
   strcpy(c[i].strName, "");
   strcpy(c[i].strID, "");
   for(j=0;j<3;j++)
    {
     c[i].fQuiz[j]=0;
    }
   for(j=0;j<2;j++)
    {
     c[i].fMacProb[j]=0;
    }
   c[i].fFinalExam=0;
   c[i].fRawScore=0;
   c[i].fFinalGrade=0;
  }
}
//displays the main menu
void displayOption()
{
 cout<<"\n ******************************";
 cout<<"\n	[1]	Add Record";
 cout<<"\n	[2]	View Student Record";
 cout<<"\n	[3]	Modify Student Record";
 cout<<"\n	[4]	View Class Record";
 cout<<"\n	[5]	EXIT";
 cout<<"\n ******************************";
}
//search for index of specified name/ID of student
int searchRecord(CLASS_RECORD c, char str[], int nMode)
{
 int nIndex = -1, i=0;
 while (i<5&&nIndex==-1)
 {
  if (nMode==NAME&&!strcmp(c[i].strName, str))
  nIndex=i;
  else if (nMode==ID&&!strcmp(c[i].strID, str))
  nIndex=i;
  i++;
 }
 return nIndex;
}
//displays the content of student record
void viewStudentRecord (CLASS_RECORD c, int n)
{
 int i;
 cout<<"\n *****STUDENT RECORD#"<<n+1<<"*****\n";
 cout<<c[n].strName;
 cout<<c[n].strID;
 for (i=0;i<3;i++)
  {
   cout<<"\n*****QUIZ#"<<i+1<<":"<<c[n].fQuiz[i];
  }
 for (i=0;i<3;i++)
  {
   cout<<"\n*****MACHINE PROBLEM#"<<i+1<<":"<<c[n].fMacProb[i];
  }
 cout<<"\n*****FINAL EXAM: "<<c[n].fFinalExam;
 cout<<"\n*****RAW SCORE: "<<c[n].fRawScore;
 cout<<"\n*****FINAL GRADE: "<<c[n].fFinalGrade<<"\n";
}
//add student record
void addRecord(CLASS_RECORD c, int *n)
{
 cout<<"*****ADD RECORD*****\n";
 cout<<"STUDENT NAME: ";
 cin>>c[*n].strName;
 cout<<"STUDENT ID: ";
 cin>>c[*n].strID;
 *n=*n+1;
}
//display the option for the input of grades
void displayOptionInput()
{
 cout<<"\n****************************************\n";
 cout<<"\n [1] Eneter New Student Name ";
 cout<<"\n [2] Eneter New Student ID ";
 cout<<"\n [3] Eneter Quiz#1 ";
 cout<<"\n [4] Eneter Quiz#2 ";
 cout<<"\n [5] Eneter Quiz#3 ";
 cout<<"\n [6] Eneter Machine Problem#1 ";
 cout<<"\n [7] Eneter Machine Problem#2 ";
 cout<<"\n [8] Eneter Final Exam ";
 cout<<"\n [9] Eneter DISPLAY ";
 cout<<"\n [10] Eneter EXIT ";
 cout<<"\n****************************************\n";
}
//computation............
void computeAveQ(CLASS_RECORD c, int n)
{
 int i;
 c[n].fAveQ=0;
 for (i=0;i<3;i++)
  {
   c[n].fAveQ+=c[n].fQuiz[i];
  }
 c[n].fAveQ/=3;
}
void computeAveMP(CLASS_RECORD c, int n)
{
 int i;
 c[n].fAveMP=0;
 for (i=0;i<2;i++)
 {
  c[n].fAveMP+=c[n].fMacProb[i];
 }
 c[n].fAveMP/=2;
}
void computeRawScore(CLASS_RECORD c, int n)
 {
 c[n].fRawScore=(c[n].fAveQ+c[n].fAveMP+c[n].fFinalExam)/3;
 }
void computeFinalGrade(CLASS_RECORD c, int x)
{
 if (c[x].fRawScore>=94)
 c[x].fFinalGrade=1.00;
}
void modifyRecord(CLASS_RECORD c, int n)
{
 int mode, num;
 num=n+1;
 cout<<"You are going to modify record #"<<num;
 viewStudentRecord (c, n);
 do
 {
  displayOptionInput();
  cout<<"********************\n\n";
  cout<<"ENTER YOUR OPTION: ";
  cin>>mode;
  cout<<"********************\n\n";

  switch(mode)
  {
   case NAME:
   {
    cout<<"NEW NAME:";
    cin>>c[n].strName;
    break;
   }
   case ID:
   {
    cout<<"NEW ID:";
    cin>>c[n].strID;
    break;
   }
   case QUIZ1:
   {
    cout<<"NEW QUIZ#1:";
    cin>>c[n].fQuiz[0];
    break;
   }
   case QUIZ2:
   {
    cout<<"NEW QUIZ#2:";
    cin>>c[n].fQuiz[1];
    break;
   }
   case QUIZ3:
   {
    cout<<"NEW QUIZ#3:";
    cin>>c[n].fQuiz[2];
    break;
   }
   case MP1:
   {
    cout<<"NEW MP1: ";
    cin>>c[n].fMacProb[0];
    break;
   }
   case MP2:
   {
    cout<<"NEW MP2: ";
    cin>>c[n].fMacProb[1];
    break;
   }
   case FE:
   {
    cout<<"NEW FE: ";
    cin>>c[n].fFinalExam;
    break;
   }
   case 9:
   {
    viewStudentRecord(c, n);
    break;
   }
  }
   computeAveQ(c, n);
   computeAveMP(c, n);
   computeRawScore(c, n);
   computeFinalGrade(c, n);
 }
  while (mode!=10);
}
void chooseNameOrID(string50 *str, int *nMode)
{
 cout<<"[1] Student Name\n";
 cout<<"[2] Student ID\n";
 cout<<"choose: ";
 cin>>*nMode;

 if(*nMode==NAME)
 cout<<"STUDENT NAME: ";
 else if(*nMode==ID)
 cout<<"STUDENT ID: ";
 cin>>*str;
}
void viewClassRecord(CLASS_RECORD c)
{
 int nInterval=1,i,nStart=0,bValid=1,y;
 char ch='\0';
 do
 {
  bValid=1;
  cout<<"Enter [P]rev, [N]ext or [Q]uit: ";
  cin>>ch;
  if (ch=='P'||ch=='p')
  {
   for (i=0;i<nInterval;i++)
   if (nStart==0)
   nStart=4;
   else
   nStart--;
  }
  if (ch=='N'||ch=='n')
  {
   nStart=(nStart+nInterval)%5;
  }
  if (bValid)
  for (i=0;i<nInterval;i++)
  {
   y=(nStart+1)%5;
   viewStudentRecord(c, y);
  }
 }
 while (ch!='Q'&&ch!='q');
}
void main()
{
 clrscr();

 CLASS_RECORD classRec;
 string50 string;
 int mode, numRec, choice, index;

 initialize(classRec);
 strcpy(string, "");
 do
 {
  displayOption();
  cout<<"***************\n";
  cout<<"OPTION: ";
  cin>>choice;
  cout<<"***************\n";

  switch(choice)
  {
   case 1:
   {
    addRecord(classRec, &numRec);
    cout<<"NUM REC"<<numRec;
    break;
   }
   case 2:
   {
    chooseNameOrID(&string,&mode);
    index=searchRecord(classRec, string, mode);
    viewStudentRecord(classRec, index);
    break;
   }
   case 3:
   {
    chooseNameOrID(&string,&mode);
    index=searchRecord(classRec, string, mode);
    modifyRecord(classRec, index);
    break;
   }
   case 4:
   {
    viewClassRecord(classRec);
    break;
   }
  }
 }
 while (choice!=5);
}