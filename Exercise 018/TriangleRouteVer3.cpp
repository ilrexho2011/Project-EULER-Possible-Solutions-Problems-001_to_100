#include <iostream>
using namespace std;

int CrunchSmallTriangle(int top[], int middle[], int bottom[])
{
    int biggest=0;
    if(middle[0]+bottom[0] > biggest) biggest=middle[0]+bottom[0];
    if(middle[0]+bottom[1] > biggest) biggest=middle[0]+bottom[1];
    if(middle[1]+bottom[0] > biggest) biggest=middle[1]+bottom[0];
    if(middle[1]+bottom[1] > biggest) biggest=middle[1]+bottom[1];
    return biggest+top[0];
}

template<std::size_t TopN, std::size_t MidN, std::size_t BotN>
void ConsolidateBottomThreeRows(int (&top)[TopN],
                                int (&middle)[MidN],
                                int (&bottom)[BotN])
{
    int SmallTop[1], SmallMiddle[2], SmallBottom[3];
    for (std::size_t x = 0; x != TopN; ++x)
    {
        SmallTop[0] = top[x];
        SmallMiddle[0] = middle[x];
        SmallMiddle[1] = middle[x + 1];
        SmallBottom[0] = bottom[x];
        SmallBottom[1] = bottom[x + 1];
        SmallBottom[2] = bottom[x + 2];
        top[x] = CrunchSmallTriangle(SmallTop, SmallMiddle, SmallBottom);
    }
}

int main()
{
    int row1[1]={75};
    int row2[2]={95,64};
    int row3[3]={17,47,82};
    int row4[4]={18,35,87,10};
    int row5[5]={20,4,82,47,65};
    int row6[6]={19,1,23,75,3,34};
    int row7[7]={88,2,77,73,7,63,67};
    int row8[8]={99,65,4,28,6,16,70,92};
    int row9[9]={41,41,26,56,83,40,80,70,33};
    int row10[10]={41,48,72,33,47,32,37,16,94,29};
    int row11[11]={53,71,44,65,25,43,91,52,97,51,14};
    int row12[12]={70,11,33,28,77,73,17,78,39,68,17,57};
    int row13[13]={91,71,52,38,17,14,91,43,58,50,27,29,48};
    int row14[14]={63,66,4,68,89,53,67,30,73,16,69,87,40,31};
    int row15[15]={4,62,98,27,23,9,70,98,73,93,38,53,60,4,23};

    ConsolidateBottomThreeRows(row13, row14, row15);
    ConsolidateBottomThreeRows(row11, row12, row13);
    ConsolidateBottomThreeRows(row9, row10, row11);
    ConsolidateBottomThreeRows(row7, row8, row9);
    ConsolidateBottomThreeRows(row5, row6, row7);
    ConsolidateBottomThreeRows(row3, row4, row5);
    ConsolidateBottomThreeRows(row1, row2, row3);

    cout<<row1[0];
}
