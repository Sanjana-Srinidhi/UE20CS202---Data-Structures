#include "PES2UG20CS549_H.h"
    
int main()
{
    header *head;
    int start_x=0;
    int start_y=0;
    int end_x = 0;
    int end_y = 0;
    head = readMap(&start_x, &start_y, &end_x, &end_y);
    storePath(head->right, start_x, start_y, end_x, end_y);
    return 0;
}