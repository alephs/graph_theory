// Compressing Binary Matrices for Space Saving and (possibly) Performance
// written by Johnny Viel 5.12.16
//
// This program uses the (1,0) nature of binary matrices to compress their size.
// Since the rows of a binary matrix are represented as 1s and 0s, then a single
// decimal number can be used to represent each row, the binary representation of which
// has the same sequence of 1s and 0s.
//
// The intended use for this technique is to make a more performant library for graph theory
// but it may be extensible to other applications.
//
// In the below example, I have compressed an 8x8 binary matrix (128 bytes) to an 8x1 decimal
// matrix (16 bytes). The compression factor is sqrt( 2 * # bytes in orig. matrix ) 
//
// sources: None

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    short int regMat[64] = 
        {
            0,1,0,1,0,1,0,1,
            1,0,1,0,1,0,1,0,
            0,1,0,1,0,1,0,1,
            1,0,1,0,1,0,1,0,
            0,1,0,1,0,1,0,1,
            1,0,1,0,1,0,1,0,
            0,1,0,1,0,1,0,1,
            1,0,1,0,1,0,1,0
        };
    // equivalent matrix, with decimal representations of 'rows' of regMat[]
    // takes up sqrt(cardinality of regMat) spaces in memory.
    short int bitMat[8] = 
        {
            85,  // 85  in binary = 01010101
            170, // 170 in binary = 10101010
            85,
            170,
            85,
            170,
            85,
            170,
        };

    // print regular matrix
    int regSize = sizeof(regMat)/sizeof(short int);
    int carriageRet = sqrt(regSize);
    cout << "regular matrix = " << sizeof(regMat) << " bytes" << endl;
    for(int i=0; i<regSize;)
    {
        for( int x=0; x<carriageRet; x++ )
            cout << regMat[i++] << " ";
        cout << endl;
    }

    // print bit matrix
    int numBits = sizeof(short int)*8; // calculates the number of bits in the data type (short int in this case)
    int bitMatSize = sizeof(bitMat)/sizeof(short int);
    cout << "\n\nbit matrix = " << sizeof(bitMat) << " bytes" << endl;
    short int masterMask = pow(2,bitMatSize-1);
    short int curMask;
/*    short int masks[16] = 
        {
            1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768
        };
*/
    for( int i=0; i<bitMatSize; i++ )
    {
        curMask = masterMask;
        for( int x=0; x<8; x++ ){
            cout << ( (bitMat[i] & curMask) > 0 ) << " "; // uses bitmask to print either a '1' or '0' depending on what's in that slot 
            curMask >>= 1;
        }
        cout << endl;
    }
    return 0;
}
