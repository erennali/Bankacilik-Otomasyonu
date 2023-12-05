#include <iostream> 
#include <locale.h>
#include <string>
#include <string.h>
#include <time.h>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <fstream> 

using namespace std;
void parayatirma();
void bakiyesorgulama();
void hesaphareketleri();
void paracekme();
int kontrol();


int main()
{
	kontrol();
	char secim;
	do
{
		
	system("cls");
	setlocale(LC_ALL, "Turkish");
	cout<<"|\\        BANKACILIK OTOMASYONU       /|"<<endl<<endl<<endl;
	cout<<"-----------------------------------------"<<endl;
	cout<<"|       1-Para Yatýrma                  |"<<endl;
	cout<<"|       2-Para Çekme                    |"<<endl;
	cout<<"|       3-Bakiye Sorgulama              |"<<endl;
	cout<<"|       4-                              |"<<endl;
	cout<<"|       5-Hesap Hareketleri             |"<<endl;
	cout<<"-----------------------------------------"<<endl;
	
	secim=getche();
	cout<<endl<<endl<<endl<<endl<<endl;
	
	switch(secim)
	{
		case '1':
			{
				parayatirma();
				break;
			}
		case '2':
			{
				paracekme();
				break;
			}
		case '3':
			{
			bakiyesorgulama();
				break;
			}
		case '4':
			{
				
				break;
			}
		case '5':
			{
				hesaphareketleri();
				break;
			}
		default:
			
			
			cout<<"HATALI TUÞLAMA!\n";
		
}
lan:
cout<<"\n\n\n\nAna menüye dönmek ister misiniz?(e/h): ";
		secim=getche();
		if(secim!='e'&& secim!='E'&&secim!='h'&&secim!='H')
		{
		cout<<"\n\nLütfen doðru tuþlama yapýnýz!"<<endl;
		goto lan;}
}while(secim=='e' || secim=='E');
	
	
	

	return 0;
	
	
}

void parayatirma()
{
	int para=0;
	char teklif;
	int giris;
	
	
	
	do
	{
		ofstream yaz("giris.dat",ios::binary | ios::app);
	cout<<"\n	Kaç lira yatýrmak istiyorsunuz: ";
	cin>>giris;
		yaz<<'+'<<giris<<endl;
		yaz.close();
		ifstream oku("bakiye.dat",ios::binary);
	oku>>para;
	oku.close();
    para+=giris;

	
	ofstream bakiye("bakiye.dat",ios::binary);
	bakiye<<para;
	bakiye.close();
	cout<<"Para eklemek istiyor musunuz?(e/h): ";
	
	teklif=getche();
	}while (teklif=='e' || teklif=='E');
	
    
}

void hesaphareketleri()
{
	ifstream oku("giris.dat",ios::binary | ios::app);
	string cumle;
	while ( getline(oku,cumle) )
      cout << cumle << endl;
      oku.close();
}

void paracekme()
{
	int para=0;
	char teklif;
	int giris;
	
	do
	{
		ofstream yaz("giris.dat",ios::binary | ios::app);
	cout<<"\n	Kaç lira çekmek istiyorsunuz: ";
	cin>>giris;
	yaz<<'-'<<giris<<endl;
		yaz.close();
		ifstream oku("bakiye.dat",ios::binary);
	oku>>para;
	oku.close();
    para-=giris;

	
	ofstream bakiye("bakiye.dat",ios::binary);
	bakiye<<para;
	cout<<"Tekrar çekmek istiyor musunuz?(e/h): ";
	
	teklif=getche();
	}while (teklif=='e' || teklif=='E');

}

void bakiyesorgulama()
{
	ifstream oku("bakiye.dat",ios::binary);
	int paramiz;
	oku>>paramiz;
	cout<<"GÜNCEL BAKÝYE: "<<paramiz<<endl;
}

int kontrol()
{
	string girilen;
	
	cout<<"\nNOT:Sifre:eren\n\n Sisteme Giris Yapmak Icin Sifreyi Giriniz: ";
	cin>>girilen;
	
	if(girilen=="eren" || girilen=="EREN")
	{
	cout<<"\nGIRIS BASARILI\n";
	return 1;}
	else
	{
	cout<<"\nSIFRE HATALI\n";
	return kontrol();}
}
