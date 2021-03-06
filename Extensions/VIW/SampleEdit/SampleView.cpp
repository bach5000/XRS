/***************************************
/
/	SimpleJuice beta 02
/
/   Something like a DrumMachine.
/	Original idea by Andrea Anzani
/	
/	I hope to find someone that can help me in get
/	this app better!
/	Please write two lines to me.
/
/	andrea.anzani@lib.disco.unimib.it
/
*****************************************/

#include "SampleView.h"
#include <stdio.h>
#include <stdlib.h>



SampleView::SampleView(BRect vframe): BView(vframe,"x",0,B_WILL_DRAW|B_FRAME_EVENTS|B_PULSE_NEEDED)
{
	SetViewColor(0,0,0);
	SetLowColor(0,0,0);
	SetHighColor(255,255,255);
	SetFontSize(8);
	
	data=NULL;
	clip=false;
	sampleCount=1024;
	
		
}

void
SampleView::Init(void *dat,int32 count,bool c)
{
	data=dat;
	sampleCount=count;
	clip=c;
	Invalidate();
}


void
SampleView::Draw(BRect b)
{
	int32 i; 
	int64 incy;
	
	
	int incx=0;
	float zero=(Bounds().Height())/2;
 	int32 rtn;
 	
 	float y,y2;
 	incy=(float)32767/zero;
 	
 	//StrokeLine(BPoint(40,0),BPoint(40,Bounds().bottom));
	//StrokeLine(BPoint(0,zero),BPoint(80,zero));

	MovePenTo(0,zero);
	
	//sampleCount=1;
	//sampleCount=x_synth->GetAudio(left,right,sampleCount);
	if(data==NULL)
	{
		StrokeLine(BPoint(0,zero),BPoint(Bounds().Width(),zero));
	}
	
	else
	
	{
	
	incx=(int)(sampleCount/Bounds().Width());
		
	if(sampleCount>0)
	{
		
		for(i=0;i<Bounds().IntegerWidth();i++)
		{
		
		memcpy(&right,(char*)data+(i*incx)*2,2);
		 y=(float)((zero)+(right/incy));
	 	//y2=(float)((zero)+(left[i*incx]/incy));
	       
     		SetHighColor(10,200,10);
     		StrokeLine(BPoint(i,zero),BPoint(i,y)); 
     		if(clip)
     		{
     			SetHighColor(255,0,0);
     			DrawString("Clip!",BPoint(Bounds().right-40,Bounds().bottom-5));
     			
     		}
	 	//SetHighColor(200,10,10);
	 	//StrokeLine(BPoint(i+41,zero),BPoint(i+41,y2));
		}
	
	}
	}

}