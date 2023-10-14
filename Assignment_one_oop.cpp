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
    cout<<"1-Black & White Filter\n2-Invert Filter\n3-Merge Filter \n4-Flip Image\n5-Rotate Image \n6-Darken and Lighten Image\n7-Detect Image Edges \n8-Enlarge Image\n9-Shrink Image\n10-Mirror 1/2 Image\n11-Shuffle Image\n12-Blur Image\n13-Crop Image\n14-Skew Image Right  \n15-Skew Image Up  \n16-Save the image to a file\n";
    while (choice!=0){
        cout<<"Please select a filter to apply or 0 to exit: \n";
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
                Skew_Image();
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

void copyImageToSec()
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
                image[i][j]=0;
            else
                image[i][j]=255;
        }
    }
}

void InvertImage(){
    // code
}

void MergeImages(){
    // code
}

void  Flip_Image()
{
    cout << "Flip (h)orizontally or (v)ertically ? \n" ;
    char c ;
    cin >> c ;
    if(c == 'h') // horizontally
    {
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE/2; ++j)
            {
                swap(image[i][j],image[i][SIZE-1-j]) ;
            }

        }
    }
    else // vertically
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
    // code
}

void Detect_Image_Edges()
{
    BlackandWhite() ;
    int last = image[0][0] ;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE ; ++j) {
            if(last != image[i][j])
            {
                last = image[i][j] ;
                image[i][j] = 0 ;
            }
            else
                image[i][j] = 255 ;
        }
    }

}

void EnlargeImage(){
    // code
}
void ShrinkImage(){
    // code
}
void DarkenandLighten(){
    // code
}

void Mirror_half_Image()
{
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?\n" ;
    char c ; cin >> c ;
    if(c=='l')
    {
        for (int i = 0 ; i < SIZE; ++i) {
            for (int j = SIZE/2; j < SIZE; ++j) {
                image[i][j] = image[i][SIZE-j-1] ;
            }

        }
    }
    else if(c=='r')
    {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE/2; ++j) {
                image[i][j] = image[i][SIZE-j-1] ;
            }
        }
    }
    else if(c=='u')
    {
        for (int i = SIZE/2; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] = image[SIZE-i-1][j] ;
            }
        }
    }
    else
    {
        for (int i = 0; i < SIZE/2; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                image[i][j] = image[SIZE-i-1][j] ;
            }

        }
    }
}

void Shuffle_Image()
{
    // code
}

void BlurImage(){
    // code
}

void  Crop_Image()
{
    int x, y, l, w;
    cout << "Please enter x y l w:\n" ;
    cin >> x >> y >> l >> w ;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if(i<x || i>x+l || j<y || j>y+w) // out of the rectangle
                image[i][j] = 255 ; // make it white
        }
    }
}
void Skew_Image(){
    // code
}


