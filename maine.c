#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
	int zi;
	int luna;
	int an;
}DATA;

int este_an_bisect(DATA d)
{
	if((d.an%4==0 && d.an%100!=0)||(d.an%400==0))
	{
		return 1;
	}
	else
		return 0;
}

int nr_de_zile(DATA d)
{
	int zile_in_luna[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if (este_an_bisect(d)&&d.luna==2)
	{
		return 29;
	}
	else
		return zile_in_luna[d.luna-1];
}

void main()
{
	system("cls");
	DATA azi,maine;
	printf("Tastati data curenta(zi,luna,an):");
	scanf("%d %d %d",&azi.zi,&azi.luna,&azi.an);
	maine=azi;

	if (azi.zi!=nr_de_zile(azi))
	{
		maine.zi=azi.zi+1;
	}
	else if (azi.luna==12)
	{
		maine.zi=1;
		maine.luna=1;
		maine.an++;
	}
	else
	{
		maine.zi=1;
		maine.luna++;
	}

	//printf("Data de maine este:%d %d %d\n",maine.zi,maine.luna,maine.an);

	int numar;
	int centurycode=0;
	numar=azi.an%100;

	if (azi.an/100==17)
	{
		centurycode=0;
	}
	else if (azi.an/100==18)
	{
		centurycode=5;
	}
	else if (azi.an/100==19)
	{
		centurycode=3;
	}
	else if (azi.an/100==20)
	{
		centurycode=2;
	}
	else if (azi.an/100==21)
	{
		centurycode=0;
	}
	else if (azi.an/100==22)
	{
		centurycode=5;
	}
	else if (azi.an/100==23)
	{
		centurycode=3;
	}
	else if (azi.an/100==24)
	{
		centurycode=2;
	}
	else if (azi.an/100==25)
	{
		centurycode=0;
	}
	else if (azi.an/100==26)
	{
		centurycode=5;
	}
	else if (azi.an/100==27)
	{
		centurycode=3;
	}
	else if (azi.an/100==28)
	{
		centurycode=2;
	}
	else if (azi.an/100==29)
	{
		centurycode=0;
	}
	else if (azi.an/100==30)
	{
		centurycode=5;
	}
	
	//printf("%d\n",centurycode);
	int doomsday=0;
	if (azi.luna==1 && este_an_bisect(azi))
	{
		doomsday=4;
	}
	else
	{
		doomsday=3;
	}

	 if (azi.luna==2 && este_an_bisect(azi))
	{
		doomsday=29;
	}
		else 
	{
		doomsday=28;
	}

	 if (azi.luna==3)
	{
		doomsday=14;
	}
	else if (azi.luna==4)
	{
		doomsday=4;
	}
	else if (azi.luna==5)
	{
		doomsday=9;
	}
	else if (azi.luna==6)
	{
		doomsday=6;
	}
	else if (azi.luna==7)
	{
		doomsday=11;
	}
	else if (azi.luna==8)
	{
		doomsday=8;
	}
	else if (azi.luna==9)
	{
		doomsday=5;
	}
	else if (azi.luna==10)
	{
		doomsday=10;
	}
	else if (azi.luna==11)
	{
		doomsday=7;
	}
	else if (azi.luna==12)
	{
		doomsday=12;
	}

	//printf("%d %d %d\n",centurycode,doomsday,numar);

	int cat;
	int rest1;
	int rest2;
	int numar2;
	int suma;

	if (azi.an==1700 || azi.an== 1800 || azi.an==1900 || azi.an==2000 || azi.an==2100 || azi.an==2200 || azi.an==2300 || azi.an==2400 || azi.an==2500 || azi.an==2600 || azi.an==2700 || azi.an==2800 || azi.an==2900 || azi.an==3000) 
	{
		cat=0;
	}
	else
	{	
	cat=numar/12;
	}
	//printf("%d\n",cat);
	rest1=numar-(cat*12);
	//printf("%d\n",rest1);
	rest2=rest1/4;
	//printf("%d\n",rest2);

	if (azi.zi>=doomsday)
	{
		numar2=azi.zi-doomsday;
		while (numar2>7)
		{
			numar2=numar2-7;
		}
		suma=centurycode+cat+rest1+rest2+numar2;
	}
	else if (azi.zi<=doomsday)
	{
		numar2=doomsday-azi.zi;
		while (numar2>7)
		{
			numar2=numar2-7;
		}
		suma=centurycode+cat+rest1+rest2-numar2;
	}
	//printf("%d\n",suma);


	while (suma>=7)
	{
		suma=suma-7;
	}
	printf("Ziua din saptamana este:");
	if (suma==0)
	{
		printf("Duminica");
	}
	else if (suma==1)
	{
		printf("Luni");
	}
	else if (suma==2)
	{
		printf("Marti");
	}
	else if (suma==3)
	{
		printf("Miercuri");
	}
	else if (suma==4)
	{
		printf("Joi");
	}
	else if (suma==5)
	{
		printf("Vineri");
	}
	else if (suma==6)
	{
		printf("Sambata");
	}
	
}
