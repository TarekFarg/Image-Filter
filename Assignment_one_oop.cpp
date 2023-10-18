// FCAI – OOP Programming – 2023 - Assignment 1
// Program Name: CS213-2023-20220009-20220171-NO ID-Part1.cpp
// Last Modification Date:	9/10/2023
// Author1 and ID :	Tarek Mohamed Abdullah farg     20220171
// Author2 and ID :	ahmad osama mahmoud mohamed     20220009
// Author3 and ID :	Alaa Eldin Hassan Ahmed         NO ID
// Purpose: Creating a program to edit images


#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "bmplib.cpp"

using namespace std;
unsigned char image[SIZE][SIZE], SecImage[SIZE][SIZE];


void loadImage ();
void loadSecImage ();
void saveImage ();
void copyImageToSec() ;
void BlackandWhite();
void InvertImage();
void MergeImages();
void Flip_Image();
void DarkenandLighten();
void RotateImage();
void Detect_Image_Edges() ;
void EnlargeImage();
void ShrinkImage();
void Mirror_half_Image() ;
void  Shuffle_Image() ;
void BlurImage();
void  Crop_Image() ;
void Skew_Image();



int main() {

    cout<<"Ahlan ya user ya habibi"<<endl;
    loadImage();
    int choice=1;
    cout<<"1-Black & White Filter\n2-Invert Filter\n3-Merge Filter \n4-Flip Image\n5-Rotate Image \n6-Darken and Lighten Image\n7-Detect Image Edges \n8-Enlarge Image\n9-Shrink Image\n10-Mirror 1/2 Image\n11-Shuffle Image\n12-Blur Image\n13-Crop Image\n14-Skew Image Horizontal  \n15-Skew Image Vertical \n16-Save the image to a file\n";
    while (choice!=0){
        cout<<"Please select a filter to apply or 16 to save or 0 to exit: \n";
        cin>>choice;
        switch (choice) {
            case 0:
                break;
            case 1:
                BlackandWhite();
                break;
            case 2:
                InvertImage();
                break;
            case 3:
                MergeImages();
                break;
            case 4:
                Flip_Image();
                break;
            case 5:
                RotateImage();
                break;
            case 6:
                DarkenandLighten();
                break;
            case 7:
                Detect_Image_Edges() ;
                break;
            case 8:
                EnlargeImage();
                break;
            case 9:
                ShrinkImage();
                break;
            case 10:
                Mirror_half_Image() ;
                break;
            case 11:
                Shuffle_Image() ;
                break;
            case 12:
                BlurImage();
                break;
            case 13:
                Crop_Image() ;
                break;
            case 14:
                void Skew_Image_Horizontal();
            case 15:
                void Skew_Image_Vertical();
            case 16:
                saveImage();
                break;
            default:
                cout<<"Invalid\n";
        }
    }


    return 0;
}



void loadImage () {
    char imageFileName[100];

    // Get gray scale image file name
    cout << "Please enter file name of the image to process: "<<endl;
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    readGSBMP(imageFileName, image);
}

void loadSecImage () {
    char SecImageName[100];

    // Get gray scale image file name
    cout << "Please enter file name of the image to process: "<<endl;
    cin >> SecImageName;

    // Add to it .bmp extension and load image
    strcat (SecImageName, ".bmp");
    readGSBMP(SecImageName, SecImage);
}

void saveImage () {
    char imageFileName[100];

    // Get gray scale image target file name
    cout << "Enter the target image file name: \n";
    cin >> imageFileName;

    // Add to it .bmp extension and load image
    strcat (imageFileName, ".bmp");
    writeGSBMP(imageFileName, image);
}

void copyImageToSec() // make image = SecImage
{
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j] = SecImage[i][j] ;
        }
    }
}

void BlackandWhite()  {

    for (int i = 0; i < SIZE ; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if(image[i][j]<127)
                image[i][j]=0;      // make it black
            else
                image[i][j]=255;        // make it white
        }
    }
}

void InvertImage(){
        for (int i = 0; i < SIZE ; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j]=255-image[i][j];
        }
    }
}

void MergeImages(){
    loadSecImage();
    for (int i = 0; i < SIZE ; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            image[i][j]=(image[i][j]+SecImage[i][j])/2;         //we are taking the average of the two pixels
        }
    }
}

void  Flip_Image()
{
    cout << "Flip (h)orizontally or (v)ertically ? \n" ;
    char c ;
    cin >> c ;
    if(c == 'h')    // horizontally
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE/2; ++j)
            {
                swap(image[i][j],image[i][SIZE-1-j]) ;
            }

        }
    }
    else    // vertically
    {
        for (int i = 0; i < SIZE/2; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                swap(image[i][j],image[SIZE-1-i][j]) ;
            }
        }
    }

}

void RotateImage(){
    cout<<"Rotate (90), (180) or (270) degrees?\n";
    int degree;cin>>degree;
    char NewImage[SIZE][SIZE];
    if(degree==90){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                NewImage[i][j]=image[SIZE-1-j][i];
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j]=NewImage[i][j];
            }
        }
    }
    else if(degree==180){
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                NewImage[i][j]=image[SIZE-1-j][i];
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j]=NewImage[SIZE-1-j][i];
            }
        }
    }
    else{
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                NewImage[i][j]=image[j][SIZE-1-i];
            }
        }
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j]=NewImage[i][j];
            }
        }
    }
}

void Detect_Image_Edges()
{
    BlackandWhite() ;
    int last = image[0][0] ;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE ; ++j) {
            if(last != image[i][j])
            {
                last = image[i][j] ;        // update the last
                image[i][j] = 0 ;           // make it black
            }
            else
                image[i][j] = 255 ;         // make it white
        }
    }

}

void EnlargeImage(){
 cout<<"Which quarter to enlarge 1, 2, 3 or 4?\n";
    int x,a=0,b=128;
    unsigned char quarter[SIZE/2][SIZE/2];
    cin>>x;
    if(x > 2){      //quarter 3 or 4
        a=128;
    }
    if(x%2){        //quarter 1 or 3
        b=0;
    }
    for (int i = 0; i < SIZE/2; ++i) {          //get quarter data
        for (int j = 0; j < SIZE/2; ++j) {
            quarter[i][j]=image[i+a][j+b];
        }
    }

    for (int i = 0; i < SIZE/2 ; ++i) {          //enlarge quarter
        for (int j = 0; j < SIZE/2 ; ++j) {
            SecImage[2*i][2*j]=quarter[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 1; j < SIZE; j+=2) {
            SecImage[i][j]=(SecImage[i][j-1]+SecImage[i][j+1])/2;
        }
    }
    for (int i = 1; i < SIZE; i+=2) {
        for (int j = 0; j < SIZE; j++) {
            SecImage[i][j]=(SecImage[i-1][j]+SecImage[i+1][j])/2;
        }
    }
    copyImageToSec();
}

void ShrinkImage(){
    int x;
    cout<<"Which quarter to enlarge 1, 2, 3 or 4?"<<endl;
    cin>>x;
    for (int i = 0; i < SIZE ; ++i) {          //Shrink
        for (int j = 0; j < SIZE ; ++j) {
            SecImage[i/x][j/x]=image[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i) {        //to make the rest of image white
        for (int j = 0; j < SIZE; ++j) {
            if(i<SIZE/x && j<SIZE/x){
                image[i][j] = SecImage[i][j];
            }
            else
                image[i][j]=255;
        }
    }
}

void DarkenandLighten(){
    cout<<"Do you want to (d)arken or (l)ighten?\n";
    char x;cin>>x;
    int y;
    y=(255*50)/100;      //The amount by which to darken or lighten the image.

    if(x=='d'){                             //darken
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j]=max(0,image[i][j]-y);
            }
        }
    }
    else{                                   //lighten
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j]=min(255,image[i][j]+y);
            }
        }
    }
}

void Mirror_half_Image()
{
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?\n" ;
    char c ; cin >> c ;
    if(c=='l')
    {
        for (int i = 0 ; i < SIZE; ++i) {
            for (int j = SIZE/2; j < SIZE; ++j) {
                image[i][j] = image[i][SIZE-j-1] ;  // make the right side equal to the lift
            }

        }
    }
    else if(c=='r')
    {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE/2; ++j) {
                image[i][j] = image[i][SIZE-j-1] ;  // make the left side equal to teh right
            }
        }
    }
    else if(c=='u')
    {
        for (int i = SIZE/2; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] = image[SIZE-i-1][j] ;  // make the down equal to the up
            }
        }
    }
    else
    {
        for (int i = 0; i < SIZE/2; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] = image[SIZE-i-1][j] ;  // make the up equal to the down
            }

        }
    }
}

void Shuffle_Image()
{
  cout << "New order of quarters ?\n" ;
    int order ; // for new order
    int x , y , tempy; // index of SecImage
    for (int i = 0; i < 4; ++i)
    {
        cin >> order ;
        if(i==0)
            x = 0 , tempy = 0 ; // quarter 1
        else if(i==1)
            x = 0 , tempy = SIZE/2 ; // quarter 2
        else if(i==2)
            x = SIZE/2 , tempy = 0; // quarter 3
        else if(i == 3)
            x = SIZE/2 , tempy = SIZE/2 ; // quarter 4

        if(order == 1)
        {
            for (int j = 0; j < SIZE / 2; ++j) {
                y =tempy ;
                for (int k = 0; k < SIZE / 2; ++k) {
                    SecImage[x][y] = image[j][k] ;
                    y++ ;
                }
                x++ ;
            }
        }
        else if(order == 2)
        {
            for (int j = 0; j < SIZE / 2; ++j) {
                y =tempy ;
                for (int k = SIZE / 2; k < SIZE ; ++k) {
                    SecImage[x][y] = image[j][k] ;
                    y++ ;
                }
                x++ ;
            }
        }
        else if(order == 3)
        {
            for (int j = SIZE / 2; j < SIZE ; ++j) {
                y =tempy ;
                for (int k = 0 ; k < SIZE / 2 ; ++k) {
                    SecImage[x][y] = image[j][k] ;
                    y++ ;
                }
                x++ ;
            }
        }
        else if(order == 4)
        {
            for (int j = SIZE / 2; j < SIZE ; ++j) {
                y =tempy ;
                for (int k = SIZE / 2 ; k < SIZE  ; ++k) {
                    SecImage[x][y] = image[j][k] ;
                    y++ ;
                }
                x++ ;
            }
        }
    }
    copyImageToSec();//make image = SecImage

}

void BlurImage(){
    char NewImage[SIZE][SIZE];
    int dx8[8] = {0, 0, 1, -1, 1, -1, -1, 1};
    int dy8[8] = {1, -1, 0, 0, 1, -1, 1, -1};
    for (int i = 1; i < SIZE-1 ; ++i) {
        for (int j = 1; j < SIZE-1; ++j) {             //we are using kernel for blur and all kernel =1 so we are taking the average
            int sum=image[i][j];
            for (int k = 0; k < 8; ++k) {
                sum+=image[i+dx8[k]][j+dy8[k]];
            }
            NewImage[i][j]=sum/9;
        }
    }
    for (int i = 1; i < SIZE-1; ++i) {
        for (int j = 1; j < SIZE-1; ++j) {
            image[i][j]=NewImage[i][j];
            if(i==1){                       //handel border
                image[i-1][j]=image[i][j];
            }
            if(i==SIZE-2){
                image[i+1][j]=image[i][j];
            }
            if(j==1){
                image[i][j-1]=image[i][j];
            }
            if(j==SIZE-2){
                image[i][j+1]=image[i][j];
            }
        }
    }
}

void  Crop_Image()
{
    int x, y, l, w;
    cout << "Please enter x y l w:\n" ;
    cin >> x >> y >> l >> w ;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if(i<x || i>x+l || j<y || j>y+w)    // out of the rectangle
                image[i][j] = 255 ;             // make it white
        }
    }
}
void Skew_Image_Horizontal(){
cout << "please enter the angel \n" ;
    double ang ; cin >> ang ;
    ang = tan(ang*3.14159/180) ;
    int p =  round(1/ang) ;

    int move = 256 * ang , cur ;
    for (int i = 0; i < SIZE ; ++i) {          //Shrink
        for (int j = 0; j < SIZE ; ++j) {
            SecImage[i*(256-move)/256][j]=image[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i) {            // to  skew the image

        for (int j = 0; j < SIZE ; ++j) {
            cur = (256-j)*ang ;
            if(i>=cur && i < SIZE-(move-cur))
                image[i][j] = SecImage[i-cur][j] ;
            else
                image[i][j] = 255 ;
        }
    }

}
void Skew_Image_Vertical(){
      cout << "please enter the angel \n" ;
    double ang ; cin >> ang ;
    ang = tan(ang*3.14159/180) ;
    int p =  round(1/ang) ;

    int move = 256 * ang , cur ;
    for (int i = 0; i < SIZE ; ++i) {          //Shrink
        for (int j = 0; j < SIZE ; ++j) {
            SecImage[i][j*(256-move)/256]=image[i][j];
        }
    }
    for (int i = 0; i < SIZE; ++i) {            // to  skew the image
        cur = (256-i)*ang ;
        for (int j = 0; j < SIZE ; ++j) {
            if(j>=cur && j < SIZE-(move-cur))
                image[i][j] = SecImage[i][j-cur] ;
            else
                image[i][j] = 255 ;
        }
    }

}



