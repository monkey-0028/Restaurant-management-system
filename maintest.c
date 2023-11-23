#include <stdio.h> // standard lib
#include <stdlib.h>   // for getchar function only
#include <unistd.h>   // for sleep and usleep function only
#include <string.h>   // for strcat() func
//file information
//   n_ofveg.txt :: contain number of veg items stored in file {veg.txt}
//   veg.txt :: contain veg items
//   nonveg.txt :: contain non veg items
//   n_ofnonveg.txt :: contain number of non veg items stored in file{non veg items} 


int globalveg[5]={0,0,0,0,0};
int globalnonveg[5]={0,0,0,0,0};
int global=1;

// -----------------------------------------------------------------------------------------------------------------COLOR COMMANDS
#define red(a) printf("\033[1;31m%s\033[1;0m",a)
#define blue(a) printf("\033[1;94m%s\033[1;0m",a)
#define black(a) printf("\033[1;90m%s\033[1;0m",a)
#define green(a) printf("\033[1;32m%s\033[1;0m",a)
#define yellow(a) printf("\033[1;33m%s\033[1;0m",a)
#define meganta(a) printf("\033[1;35m%s\033[1;0m",a)
#define cyan(a) printf("\033[1;96m%s\033[1;0m",a)
#define byellow(a) printf("\033[1;103m%c\033[1;0m",a)  //yellow background color
//
//----------------------------------------------------------------------------------------------------------------POS
#define pos for(int space=0;space<20;space++){\
		printf(" ");\
}
// -------------------------------------------------------------------------------------------------------------FLUSH
#define flush fflush(stdout); 

// ---------------------------------------------------------------------------------------------------------FLICKER
#define flicker(color) printf("\n");\
for(int flic=0;flic<11;flic++){\
		pos\
		color(a[flic]);\
		printf("\n");\
}\
usleep(100000);\
system("clear");





// ----------------------------------------------------------------------------------------------------WELCOME + DATE
#define welcome \
printf("\n");\
printf("                    "); /* pos is not working, i don't know why*/\
printf("\033[1;92mDay:%d\033[1;0m\n",day);\
printf("                    "); /* pos is not working, i don't know why*/\
yellow("     KALUA DHABA\n");\
for(int wel=0;wel<11;wel++){\
	pos\
	printf("%s",a[wel]);\
	printf("\n");\
}
//---------------------------------------------------------------------------------------------------FPOS
#define fpos(file_handle) \
for(int sp=0;sp<20;sp++){\
	fprintf(file_handle,"%c",' ');\
}



 //why? :: cz here in many cases, printf is buffered; 	printf keep buffering data and print nothing if sleep is called, you can call \n to emty the buffer or fflush()

//-------------------------------------------------------------------------------------------------------TYPE EFFECT
#define type_effect \
	for(int out=0;out<4;out++){\
		int point=0;\
		pos\
		if(out==3){printf("\n");pos}\
		while(option1[out][point] != '\0'){\
			printf("%c",option1[out][point]);\
			fflush(stdout);\
			usleep(50000);\
			point++;\
		}\
		if(out !=3){\
		printf("\n");}\
		else{\
			printf(" ");\
		}\
	}

//-------------------------------------------------------------------------------------------------------------HIGHLIGHT EFFECT
#define highligh_effect(index) \
int ptr=0;\
while(option1[index][ptr] != '\0'){\
	welcome\
	for(int item=0;item<3;item++){\
		if(item==index){\
			pos\
			for(int mainitem=0;mainitem<ptr+1;mainitem++){\
				byellow(option1[index][mainitem]);\
			}\
			int fptr=ptr+1;\
			while(option1[index][fptr] !='\0'){\
				printf("%c",option1[index][fptr]);\
				fptr++;\
			}\
			printf("\n");\
		}\
		else{\
			pos\
			printf("%s",option1[item]);\
			printf("\n");\
		}\
	}\
ptr++;\
fflush(stdout);\
usleep(50000);\
if(option1[index][ptr] != '\0'){\
	system("clear");\
}\
}

//here lock statement is because the last option is very big and it keep executing even after the option1&2 finished; hence the if statement of option1&2 keep executing cz they are true everytime, hence amin-=1 keep decreading the value; which cause negative value in amin and loop became indefnite

//--------------------------------------------------------------------------------------------DELETE EFFECT
#define delete_effect \
system("clear");\
int lock0=0;\
int lock1=0;\
int lock2=0;\
int ex0=0;\
int ex1=0;\
int ex2=0;\
int amin=3;\
while(amin!=0){\
	welcome\
	pos\
	int ptr0=0;\
	int ptr1=0;\
	int ptr2=0;\
	while(option1[0][ptr0+ex0] !='\0' && lock0==0){\
		printf("%c",option1[0][ptr0]);\
		ptr0++;\
	}\
	if(option1[0][ex0]=='\0' && lock0==0){\
		amin-=1;\
		lock0=1;\
	}\
	printf("\n");\
	pos\
	while(option1[1][ptr1+ex1] !='\0' && lock1==0){\
		printf("%c",option1[1][ptr1]);\
		ptr1++;\
	}\
	if(option1[0][ex1]=='\0' && lock1==0){\
		amin-=1;\
		lock1=1;\
	}\
	printf("\n");\
	pos\
	while(option1[2][ptr2+ex2] !='\0' && lock2==0){\
		printf("%c",option1[2][ptr2]);\
		ptr2++;\
	}\
	if(option1[2][ex2]=='\0' && lock2==0){\
		amin-=1;\
		lock2==1;\
	}\
	ex2++;\
	ex0++;\
	ex1++;\
	fflush(stdout);\
	usleep(50000);\
	system("clear");\
}
// -----------------------------------------------------------------------------------------------------INTRO
#define intro \
if(type_effect_time!=0){\
	printf("\n");\
	pos\
	printf("\033[1;92mDay:%d\033[1;0m\n",day);\
}\
for(int i=0;i<11;i++){\
		pos\
		printf("%s",a[i]);\
		printf("\n");\
		usleep(50000);\
}
// declare functions;;;
void order_work(int day);
void bill_work();
void work_restart();
//----------------------------------------------------------------------------------------------------------------------------MAIN
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
void main(){
	system("rm data/*");
	flush
	printf("\e[?25l");  // this is ansi code to hide cursor 
	system("clear"); 
	char a[20][100]={"──────▄▀▀▀▀▀▀▀▄───────","─────▐─▄█▀▀▀█▄─▌──────","─────▐─▀█▄▄▄█▀─▌──────","──────▀▄▄▄▄▄▄▄▀───────","─────▐▀▄▄▐█▌▄▄▀▌──────","──────▀▄▄███▄▄▀───────","█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█","█░░╦─╦╔╗╦─╔╗╔╗╔╦╗╔╗░░█","█░░║║║╠─║─║─║║║║║╠─░░█","█░░╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝░░█","█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█"};
	printf("\n");
	int day=1,type_effect_time=0;
	//--------------------------------------------------------------------------INTRO EFFECT
	intro
	//--------------------------------------------------------------------------FLICKER STARTS
	system("clear");
	for(int starflic=0;starflic<3;starflic++){
			flicker(red)
			flicker(blue)
			flicker(green)
			flicker(yellow)
			flicker(meganta)
			flicker(cyan)
	}
	//---------------------------------------------------------------------------------MAIN DISPLAY(real-time)

	char option1[4][70]={"1.Order","2.Bill","3.Restart","Enter -1 to exit\n                    Select any option:"}; //----------OPTION1
	while(1){           //-------------------------------------------WHILE LOOP {MAIN DISPLAY}
		
		welcome         //---------------------------------------WELCOME{MAIN DISPLAY}
		if(type_effect_time==0){ //--------------------------TYPE EFFECT{MAIN DISPLAY}
			type_effect       
			type_effect_time++;
		}
		else{
			for(int elseop=0;elseop<4;elseop++){
				pos
				printf("%s",option1[elseop]);
				(elseop==2)?printf("\n\n"):((elseop==3)?printf(" "):printf("\n"));
				
			}
		}
		int user_input=-1; //------------------------------------USER INPUT{MAIN DISPLAY}; REASON FOR INIT;	contain garbage value which cause problem, note: input like 3 get executed cz it takes the value 3 only(%d)
		scanf("%d",&user_input);
		if(user_input==1){ //---------------------- 1.ORDER
			system("clear");
			highligh_effect(0)
			delete_effect
			intro
			order_work(day);
		}
		else if(user_input==2){ //------------------2.BILL
			system("clear");
			highligh_effect(1)
			delete_effect
			intro
			bill_work();
		}
		else if(user_input==3){ //----------------3.RESTART
			system("clear");
			for(int last=0;last<3;last++){
				pos
				red("Restart");
				flush
				usleep(200000);
				system("clear");
				flush
				usleep(200000);
			}
			if(day%5==0){
				work_restart();
			}
			day++;
			}
		else if(user_input==-1){system("clear");printf("Thank you for visiting us..\n");exit(0);}
		else{
			pos
			red("Wrong input\n");
			pos
			red("Press Enter to Try again!");
			getchar();
			getchar();
		}
		
		fflush(stdin);
		fflush(stdout);
		system("clear");
		
	}
}

//---------------------------------------------------------------------------------------------------------------------------------------------ORDER WORK
void order_work(int day){
	int vegbuy[5]={0,0,0,0,0};
	int nonvegbuy[5]={0,0,0,0,0};
	char name[30];
	char number[30];
	pos
	blue("        ORDER\n");
	pos
	printf("Name: |");
	scanf("%s",name);
	pos
	printf("Number: |");
	scanf("%s",number);
	//name and numbers are taken; now we are making BILL{id}.dat file and writing the basic info
	// ------------------------------------NAME CREATION
	char filename[40]="data//BILL{";
	char lastfilename[]="}.dat";
	strcat(filename,number);
	strcat(filename,lastfilename);
	//
	//----------------------------------BILL{id}.dat CREATION
	FILE *file;
	FILE *check;
	check=fopen(filename,"rb");
	if(check == NULL){
		file=fopen(filename,"wb");
		fprintf(file,"%s","\n");
		fpos(file)
		fprintf(file,"%s","          KALUA DHABA\n");
		fpos(file)
		fprintf(file,"%s","----------------------------------\n");
		fpos(file)	
		fprintf(file,"%s","Address: Biharsharif,Nalanda-803101\n");
		fpos(file)
		fprintf(file,"%s","Contact: KaluaBoysFromBihar@gmail.com\n");
		fpos(file)
		fprintf(file,"%s","--------BILL--------\n");
		fpos(file)
		fprintf(file,"%s","Name:");
		fprintf(file,"%s",name);
		fprintf(file,"%s","\n");
		fpos(file)
		fprintf(file,"%s","Number:");
		fprintf(file,"%s",number);
		fprintf(file,"%s","\n");
		fpos(file)
		fprintf(file,"%s","--------------------\n");
		fpos(file)
		fprintf(file,"%s","--ORDERED ITEMS--\n");
		fclose(file);  //file close
	}
	//printing ITMES heading in blue
	printf("\n");
	pos
	printf("---------");
	blue("ITEMS");
	printf("--------\n\n");
	//printing all the veg items first from the file
	//------------------------------------ITEMS MENU-----------------------------------------------
	//-----------------------------------------------------------DEFINE FOOD AND NUMBER OF FOOD;----------------------------------------------------------------||VEG||
	char veg_stock[5][50]={"0Butter Masala_","1Dal Makhani_","2Mattar Paneer_","3Dal Tadka_","4Palak Paneer_"};
	char vegfood[5][50];
	int n_ofveg=0;
	for(int additem=0;additem<5;additem++){
		if(globalveg[additem]!=-1){
			int move_char=0;
			while(1){
				if(veg_stock[additem][move_char]=='\0'){break;}
				vegfood[n_ofveg][move_char]=veg_stock[additem][move_char];
				move_char++;				
			}
			n_ofveg++;
		}
	}
	//NON VEG
	char nonveg_stock[5][50]={"0Butter Chicken_","1Chicken Tikka_","2Tandoori Chickenn_","3Chicken Biryani_","4Tangadi Kabab_"};
	char nonvegfood[5][50];
	int n_ofnonveg=0;
	for(int additem2=0;additem2<5;additem2++){
		if(globalnonveg[additem2]!=-1){
			int move_char2=0;
			while(1){
				if(nonveg_stock[additem2][move_char2]=='\0'){break;}
				nonvegfood[n_ofnonveg][move_char2]=nonveg_stock[additem2][move_char2];
				move_char2++;				
			}
			n_ofnonveg++;
		}
	}
	//writing file MENU FILE & UPDATED MENU
	if(global==1){
		FILE *menufile;
		menufile=fopen("main_menu.txt","w");
		for(int vmen=0;vmen<5;vmen++){
			int ptrtell=1;
			while(1){
				char chet;
				chet=veg_stock[vmen][ptrtell];
				if(chet=='_'){
					break;
				}
				fprintf(menufile,"%c",chet);
				ptrtell++;
			}
			fprintf(menufile,"\n");
		}
		fprintf(menufile,"\n");
		for(int nmen=0;nmen<5;nmen++){
			int ptrtell2=1;
			while(1){
				char cheet;
				cheet=nonveg_stock[nmen][ptrtell2];
				if(cheet=='_'){break;}
				fprintf(menufile,"%c",cheet);
				ptrtell2++;
			}
			fprintf(menufile,"\n");
		}
		fclose(menufile);
		FILE *update;
		update=fopen("updated_menu.txt","w");
		for(int v1t=0;v1t<n_ofveg;v1t++){
			int ptr_ofveg=1;
			while(1){
				char ch_ofveg;
				ch_ofveg=vegfood[v1t][ptr_ofveg];
				if(ch_ofveg=='_'){
					break;
				}
				fprintf(update,"%c",ch_ofveg);
				ptr_ofveg++;
			}
			fprintf(update,"\n");
		}
		fprintf(update,"\n");
		for(int nonv=0;nonv<n_ofnonveg;nonv++){
			int ptr_ofnon=1;
			while(1){
				char ch_ofnon;
				ch_ofnon=nonvegfood[nonv][ptr_ofnon];
				if(ch_ofnon=='_'){
					break;
				}
				fprintf(update,"%c",ch_ofnon);
				ptr_ofnon++;
			}
			fprintf(update,"\n");
		}
		fclose(update);

		global=0;		
	}

	//-------------------------------------------BUCKET-----------------------------------------------
	//-----------------------------------------------------------printing menu items
	int n_ofbucket=0;
	//printing the veg items//
	pos;
	printf("-Veg-");
	green("*\n");
	for(int vprint=0;vprint<n_ofveg;vprint++){
		n_ofbucket++;
		pos;
		printf("  %d.",n_ofbucket);
		int mv2=1;
		while(1){
			if(vegfood[vprint][mv2]=='_'){break;}
			printf("%c",vegfood[vprint][mv2]);
			mv2++;
		}
		printf("\n");
		flush
		usleep(30000);
	}
	//printing the non veg items//
	pos;
	printf("-Non-Veg-");
	red("*\n");
	for(int nprint=0;nprint<n_ofnonveg;nprint++){
		n_ofbucket++;
		pos;
		//little bit change the printing style of non veg items due to some error::
		printf("  %d.",n_ofbucket);
		int mv=1;
		while(1){
			if(nonvegfood[nprint][mv]=='_'){break;}
			printf("%c",nonvegfood[nprint][mv]);
			mv++;
		}
		printf("\n");
		flush
		usleep(30000);
	}
	//-----------------------------------------------------------------taking user input(order)
	printf("\n\n");
	pos
	yellow("Keep entering the order number to make an order..\n");
	pos
	blue("PRICE: each of them cost 10 rupee\n");
	pos
	yellow("Enter -1 to terminate\n");
	int order_number;
	while(1){
	printf("\n");
	pos
	scanf("%d",&order_number);
	if(order_number>0 && order_number<=n_ofveg){
		int vegmove=1;
		pos
		while(1){
			char nestedch;
			nestedch=vegfood[order_number-1][vegmove];
			if(nestedch=='_'){break;}
			printf("\033[1;32m%c\033[1;0m",nestedch);
			vegmove++;
		}
		green(" selected\n");
		//adding the value in veg buy and globalveg..
		char ch_index=vegfood[order_number-1][0];
		int index=ch_index-'0';
		vegbuy[index]++;
		globalveg[index]++;	
	}
	else if(order_number==-1){
		printf("\n");
		pos
		green("Your ordered is placed succesfully!!\n");
		pos
		green("please,wait at your table\n");
		pos
		green("Bill has been generated,you can pay after having your meal\n");
		pos
		blue("     HAVE A NICE DAY SIR/MA'M\n");
		pos
		green("press Enter to continue..");
		break;
		getchar();
		getchar();
	}
	else if(order_number>n_ofveg && order_number<=(n_ofnonveg+n_ofveg)){
		int nonvegmove=1;
		pos
		while(1){
			char nn;
			nn=nonvegfood[order_number-n_ofveg-1][nonvegmove];
			if(nn=='_'){break;}
			printf("\033[1;32m%c\033[1;0m",nn);
			nonvegmove++;			
		}
		green(" selected\n");
		//adding the value in nonvegbuy and global nonveg
		char ch_index1=nonvegfood[order_number-n_ofveg-1][0];
		int index2=ch_index1-'0';
		nonvegbuy[index2]++;
		globalnonveg[index2]++;
	}
	else{
		printf("\n");
		pos
		red("Wrong input..Try again!!");
	}

	}
	

	
	//Final writing to the bill
	FILE *final_bill;
	final_bill=fopen(filename,"ab");
	fprintf(final_bill,"\n");
	fpos(final_bill)
	fprintf(final_bill,"%s: %d\n","Day",day);
	fprintf(final_bill,"%s","                    ");	//fpos is not working here i don't know why
	fprintf(final_bill,"%s","-veg-\n");
	fpos(final_bill);
	//write here the elements;
	//veg elements;;
	int sum=0;
	for(int vwrite=0;vwrite<5;vwrite++){
		if(vegbuy[vwrite]!=0){
			char posi=1;
			while(1){
				char chwrite;
				chwrite=veg_stock[vwrite][posi];
				if(chwrite=='_'){break;}
				fprintf(final_bill,"%c",chwrite);
				posi++;
			}
			fprintf(final_bill,"----(10 x%d) Amount:%d\n",vegbuy[vwrite],vegbuy[vwrite]*10);
			sum+=vegbuy[vwrite]*10;
			fpos(final_bill);
		}
	}
	//non veg items
	fprintf(final_bill,"%s","-Non-Veg-\n");
	fpos(final_bill)
	for(int vvwrite=0;vvwrite<5;vvwrite++){
		if(nonvegbuy[vvwrite]!=0){
			char vposi=1;
			while(1){
				char vchwrite;
				vchwrite=nonveg_stock[vvwrite][vposi];
				if(vchwrite=='_'){break;}
				fprintf(final_bill,"%c",vchwrite);
				vposi++;
			}
			fprintf(final_bill,"----(10 x%d) Amount:%d\n",nonvegbuy[vvwrite],nonvegbuy[vvwrite]*10);
			sum+=nonvegbuy[vvwrite]*10;
			fpos(final_bill);
		}
	}
	fprintf(final_bill,"\n");
	fpos(final_bill)
	fprintf(final_bill,"-----------------------------------\n");
	fpos(final_bill)
	fprintf(final_bill,"Total Amount: %d\n",sum);
	fpos(final_bill)
	fprintf(final_bill,"-----------------------------------\n");
	
	


	fclose(final_bill);
	//end message--
	flush
	pos
	system("clear");
	green("Your orders are on their way!\n");
	pos
	green("Bill will be generated, Please wait at the table patiently\n");
	pos
	green("Press Enter to continue...");
	getchar();
	getchar();
	
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------------BILL WORK
void bill_work(){
	char number1[30];
	pos
	blue("        BILL\n");
	pos
	printf("Enter Number: |");
	scanf("%s",number1);
	//-------------------------------file name creation
	char filename1[40]="data//BILL{";
	char lastfilename1[10]="}.dat";
	strcat(filename1,number1);
	strcat(filename1,lastfilename1);
	//
	FILE *checkbill;
	checkbill=fopen(filename1,"rb");
	if(checkbill==NULL){
		printf("\n");
		pos
		red("Customer not found!!");
	}
	else{
		char ch;
		while(2){
			ch=fgetc(checkbill);
			if(ch=='\n'){
				flush
				usleep(30000);
			}
			if(ch==EOF){
				break;
			}
			printf("%c",ch);
		}
	}
	printf("\n");
	pos
	red("press Enter to return to the menu!");
	getchar();
	getchar();
}



void work_restart(){
int temp=globalveg[0];
for(int run=0;run<5;run++){
	if(globalveg[run]!=-1){
		if(globalveg[run]<temp){
			temp=globalveg[run];
		}
	}
}
for(int run2=0;run2<5;run2++){
	if(globalnonveg[run2]!=-1){
		if(globalnonveg[run2]<temp){
			temp=globalnonveg[run2];
		}
	}
}
for(int run3=0;run3<5;run3++){
	if(globalveg[run3]==temp){
		globalveg[run3]=-1;
	}
	if(globalnonveg[run3]==temp){
		globalnonveg[run3]=-1;
	}
}
global=1;
}




















