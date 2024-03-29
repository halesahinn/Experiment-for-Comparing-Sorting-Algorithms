/* C implementation QuickSort */
#include<stdio.h> 
#include <time.h>
#include <math.h>
    
// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 
  
/* This function takes last element or middle as pivot according to the chosen one, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */
int partition (int arr[], int low, int high) 
{
	int j;
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 
  
    for (j = low; j <= high- 1; j++) 
    { 
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) 
        { 
            i++;    // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
int partitionMiddle(int arr[], int left, int right)

{
      int i = left, j = right;
      int tmp;
      int pivot = arr[(left + right) / 2];
      while (i <= j) {
            while (arr[i] < pivot)
                  i++;
            while (arr[j] > pivot)
                  j--;
            if (i <= j) {
                  tmp = arr[i];
                  arr[i] = arr[j];
                  arr[j] = tmp;
                  i++;
                  j--;
            }
      };
      return i;
}

 

void quickSortMiddle(int arr[], int left, int right) {

      int index = partition(arr, left, right);

      if (left < index - 1)

            quickSortMiddle(arr, left, index - 1);

      if (index < right)

            quickSortMiddle(arr, index, right);

}
  
void quickSortLastPivot(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
           at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSortLastPivot(arr, low, pi - 1); 
        quickSortLastPivot(arr, pi + 1  ,high); 
    } 
} 
  

/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 
  
int main() 
{ 
    

	//reverse ordered / worst case input
    //int arr[] = {10,9,8,7,6,5,4,3,2,1};
    //int arr[] = {100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	//int arr[] = {1000, 999, 998, 997, 996, 995, 994, 993, 992, 991, 990, 989, 988, 987, 986, 985, 984, 983, 982, 981, 980, 979, 978, 977, 976, 975, 974, 973, 972, 971, 970, 969, 968, 967, 966, 965, 964, 963, 962, 961, 960, 959, 958, 957, 956, 955, 954, 953, 952, 951, 950, 949, 948, 947, 946, 945, 944, 943, 942, 941, 940, 939, 938, 937, 936, 935, 934, 933, 932, 931, 930, 929, 928, 927, 926, 925, 924, 923, 922, 921, 920, 919, 918, 917, 916, 915, 914, 913, 912, 911, 910, 909, 908, 907, 906, 905, 904, 903, 902, 901, 900, 899, 898, 897, 896, 895, 894, 893, 892, 891, 890, 889, 888, 887, 886, 885, 884, 883, 882, 881, 880, 879, 878, 877, 876, 875, 874, 873, 872, 871, 870, 869, 868, 867, 866, 865, 864, 863, 862, 861, 860, 859, 858, 857, 856, 855, 854, 853, 852, 851, 850, 849, 848, 847, 846, 845, 844, 843, 842, 841, 840, 839, 838, 837, 836, 835, 834, 833, 832, 831, 830, 829, 828, 827, 826, 825, 824, 823, 822, 821, 820, 819, 818, 817, 816, 815, 814, 813, 812, 811, 810, 809, 808, 807, 806, 805, 804, 803, 802, 801, 800, 799, 798, 797, 796, 795, 794, 793, 792, 791, 790, 789, 788, 787, 786, 785, 784, 783, 782, 781, 780, 779, 778, 777, 776, 775, 774, 773, 772, 771, 770, 769, 768, 767, 766, 765, 764, 763, 762, 761, 760, 759, 758, 757, 756, 755, 754, 753, 752, 751, 750, 749, 748, 747, 746, 745, 744, 743, 742, 741, 740, 739, 738, 737, 736, 735, 734, 733, 732, 731, 730, 729, 728, 727, 726, 725, 724, 723, 722, 721, 720, 719, 718, 717, 716, 715, 714, 713, 712, 711, 710, 709, 708, 707, 706, 705, 704, 703, 702, 701, 700, 699, 698, 697, 696, 695, 694, 693, 692, 691, 690, 689, 688, 687, 686, 685, 684, 683, 682, 681, 680, 679, 678, 677, 676, 675, 674, 673, 672, 671, 670, 669, 668, 667, 666, 665, 664, 663, 662, 661, 660, 659, 658, 657, 656, 655, 654, 653, 652, 651, 650, 649, 648, 647, 646, 645, 644, 643, 642, 641, 640, 639, 638, 637, 636, 635, 634, 633, 632, 631, 630, 629, 628, 627, 626, 625, 624, 623, 622, 621, 620, 619, 618, 617, 616, 615, 614, 613, 612, 611, 610, 609, 608, 607, 606, 605, 604, 603, 602, 601, 600, 599, 598, 597, 596, 595, 594, 593, 592, 591, 590, 589, 588, 587, 586, 585, 584, 583, 582, 581, 580, 579, 578, 577, 576, 575, 574, 573, 572, 571, 570, 569, 568, 567, 566, 565, 564, 563, 562, 561, 560, 559, 558, 557, 556, 555, 554, 553, 552, 551, 550, 549, 548, 547, 546, 545, 544, 543, 542, 541, 540, 539, 538, 537, 536, 535, 534, 533, 532, 531, 530, 529, 528, 527, 526, 525, 524, 523, 522, 521, 520, 519, 518, 517, 516, 515, 514, 513, 512, 511, 510, 509, 508, 507, 506, 505, 504, 503, 502, 501, 500, 499, 498, 497, 496, 495, 494, 493, 492, 491, 490, 489, 488, 487, 486, 485, 484, 483, 482, 481, 480, 479, 478, 477, 476, 475, 474, 473, 472, 471, 470, 469, 468, 467, 466, 465, 464, 463, 462, 461, 460, 459, 458, 457, 456, 455, 454, 453, 452, 451, 450, 449, 448, 447, 446, 445, 444, 443, 442, 441, 440, 439, 438, 437, 436, 435, 434, 433, 432, 431, 430, 429, 428, 427, 426, 425, 424, 423, 422, 421, 420, 419, 418, 417, 416, 415, 414, 413, 412, 411, 410, 409, 408, 407, 406, 405, 404, 403, 402, 401, 400, 399, 398, 397, 396, 395, 394, 393, 392, 391, 390, 389, 388, 387, 386, 385, 384, 383, 382, 381, 380, 379, 378, 377, 376, 375, 374, 373, 372, 371, 370, 369, 368, 367, 366, 365, 364, 363, 362, 361, 360, 359, 358, 357, 356, 355, 354, 353, 352, 351, 350, 349, 348, 347, 346, 345, 344, 343, 342, 341, 340, 339, 338, 337, 336, 335, 334, 333, 332, 331, 330, 329, 328, 327, 326, 325, 324, 323, 322, 321, 320, 319, 318, 317, 316, 315, 314, 313, 312, 311, 310, 309, 308, 307, 306, 305, 304, 303, 302, 301, 300, 299, 298, 297, 296, 295, 294, 293, 292, 291, 290, 289, 288, 287, 286, 285, 284, 283, 282, 281, 280, 279, 278, 277, 276, 275, 274, 273, 272, 271, 270, 269, 268, 267, 266, 265, 264, 263, 262, 261, 260, 259, 258, 257, 256, 255, 254, 253, 252, 251, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240, 239, 238, 237, 236, 235, 234, 233, 232, 231, 230, 229, 228, 227, 226, 225, 224, 223, 222, 221, 220, 219, 218, 217, 216, 215, 214, 213, 212, 211, 210, 209, 208, 207, 206, 205, 204, 203, 202, 201, 200, 199, 198, 197, 196, 195, 194, 193, 192, 191, 190, 189, 188, 187, 186, 185, 184, 183, 182, 181, 180, 179, 178, 177, 176, 175, 174, 173, 172, 171, 170, 169, 168, 167, 166, 165, 164, 163, 162, 161, 160, 159, 158, 157, 156, 155, 154, 153, 152, 151, 150, 149, 148, 147, 146, 145, 144, 143, 142, 141, 140, 139, 138, 137, 136, 135, 134, 133, 132, 131, 130, 129, 128, 127, 126, 125, 124, 123, 122, 121, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	
	//random
 	//int arr[] = {4, 6, 8, 2, 3, 10, 1, 9, 7, 5};
 	//int arr[] = {52, 54, 4, 39, 88, 48, 62, 6, 49, 43, 47, 5, 93, 3, 53, 9, 33, 100, 34, 70, 35, 57, 14, 21, 24, 56, 12, 89, 30, 17, 29, 75, 67, 58, 25, 64, 10, 94, 78, 13, 18, 77, 32, 38, 51, 41, 99, 36, 69, 20, 50, 91, 61, 73, 19, 7, 63, 31, 68, 65, 44, 60, 71, 80, 26, 97, 46, 11, 59, 92, 27, 74, 86, 45, 23, 55, 84, 79, 83, 28, 85, 42, 95, 82, 37, 81, 22, 90, 96, 40, 87, 98, 1, 15, 72, 16, 76, 2, 66, 8};
	int arr[] = {946, 170, 748, 749, 695, 6, 939, 763, 532, 605, 404, 269, 944, 913, 700, 873, 821, 602, 159, 70, 955, 985, 240, 835, 68, 406, 381, 43, 37, 303, 880, 761, 830, 504, 550, 776, 149, 686, 858, 220, 511, 375, 650, 319, 158, 21, 829, 540, 388, 110, 582, 697, 265, 982, 242, 8, 950, 432, 601, 180, 979, 393, 707, 796, 879, 48, 113, 335, 704, 690, 329, 780, 759, 656, 472, 663, 541, 530, 523, 69, 512, 638, 118, 407, 131, 487, 467, 173, 51, 325, 98, 710, 548, 961, 736, 212, 865, 459, 73, 350, 867, 938, 696, 359, 235, 840, 960, 801, 380, 551, 308, 805, 625, 629, 676, 693, 57, 612, 957, 19, 468, 371, 190, 811, 188, 989, 579, 363, 904, 143, 405, 369, 227, 465, 477, 138, 183, 148, 716, 813, 192, 480, 996, 798, 491, 758, 907, 162, 94, 340, 618, 851, 462, 95, 792, 951, 208, 187, 899, 178, 885, 767, 642, 63, 959, 5, 654, 765, 917, 861, 417, 456, 244, 956, 207, 883, 1000, 156, 875, 18, 896, 488, 213, 337, 902, 609, 966, 862, 237, 114, 198, 345, 77, 756, 545, 116, 473, 443, 588, 484, 646, 171, 441, 747, 216, 427, 322, 505, 672, 850, 892, 871, 460, 139, 124, 157, 753, 667, 499, 969, 583, 853, 391, 718, 655, 555, 256, 197, 974, 306, 622, 537, 326, 824, 195, 429, 317, 321, 741, 174, 510, 147, 806, 666, 785, 743, 461, 24, 352, 581, 186, 649, 694, 62, 685, 787, 351, 679, 420, 409, 508, 828, 560, 558, 71, 367, 857, 376, 864, 169, 732, 185, 705, 78, 706, 658, 31, 482, 129, 151, 206, 507, 392, 779, 445, 534, 257, 918, 669, 10, 992, 1, 919, 901, 719, 594, 451, 102, 96, 203, 978, 415, 973, 79, 715, 341, 578, 314, 744, 259, 234, 418, 771, 450, 357, 940, 146, 439, 983, 722, 373, 692, 267, 100, 624, 823, 897, 929, 246, 72, 528, 723, 127, 768, 42, 40, 571, 844, 815, 452, 948, 4, 264, 506, 652, 181, 271, 636, 231, 868, 923, 434, 920, 193, 431, 289, 310, 433, 36, 691, 615, 230, 807, 657, 196, 911, 378, 394, 478, 204, 419, 906, 999, 307, 852, 825, 735, 988, 842, 481, 572, 680, 495, 699, 261, 172, 215, 117, 635, 738, 411, 75, 994, 489, 803, 346, 640, 290, 344, 621, 66, 810, 874, 490, 358, 682, 887, 997, 120, 804, 714, 633, 30, 827, 12, 542, 153, 453, 740, 619, 160, 33, 401, 140, 713, 797, 533, 724, 936, 161, 860, 332, 59, 119, 3, 586, 426, 912, 92, 826, 327, 152, 503, 164, 712, 278, 141, 105, 945, 284, 184, 395, 137, 641, 818, 933, 168, 111, 963, 123, 297, 177, 83, 538, 564, 895, 683, 788, 494, 549, 292, 643, 717, 64, 757, 634, 372, 305, 837, 882, 361, 856, 355, 927, 745, 277, 255, 986, 648, 889, 914, 525, 729, 202, 41, 954, 553, 76, 814, 791, 46, 931, 121, 903, 987, 565, 908, 708, 781, 910, 975, 563, 200, 898, 854, 947, 55, 27, 112, 536, 20, 846, 531, 390, 403, 323, 423, 47, 794, 799, 970, 774, 928, 199, 425, 447, 17, 671, 421, 56, 214, 343, 16, 464, 752, 336, 843, 304, 107, 145, 739, 607, 941, 320, 436, 675, 424, 384, 166, 448, 893, 11, 182, 362, 311, 400, 474, 616, 324, 248, 659, 23, 58, 279, 301, 972, 348, 360, 591, 189, 859, 513, 328, 593, 179, 430, 968, 126, 15, 243, 524, 61, 984, 247, 990, 356, 932, 315, 597, 574, 254, 250, 22, 471, 272, 74, 249, 251, 819, 684, 226, 834, 260, 222, 517, 330, 539, 820, 232, 338, 870, 816, 750, 977, 701, 210, 470, 599, 236, 942, 28, 347, 795, 515, 498, 368, 886, 201, 366, 283, 115, 587, 397, 318, 884, 293, 402, 53, 273, 993, 150, 677, 225, 302, 971, 493, 547, 286, 500, 408, 88, 909, 543, 935, 155, 575, 651, 34, 611, 274, 281, 845, 509, 175, 296, 85, 709, 877, 566, 229, 382, 32, 135, 312, 631, 952, 502, 81, 772, 101, 422, 374, 632, 270, 238, 604, 737, 922, 577, 414, 103, 606, 45, 60, 476, 334, 921, 9, 645, 217, 194, 800, 720, 522, 349, 54, 416, 280, 596, 300, 396, 454, 782, 316, 762, 900, 295, 383, 91, 626, 627, 628, 773, 132, 817, 413, 603, 557, 570, 841, 299, 35, 455, 590, 576, 689, 916, 268, 958, 109, 925, 165, 727, 463, 379, 802, 665, 428, 552, 387, 751, 50, 637, 991, 438, 770, 905, 726, 721, 598, 890, 647, 245, 298, 133, 285, 589, 869, 569, 673, 526, 128, 653, 760, 370, 881, 211, 678, 266, 554, 809, 134, 364, 331, 754, 662, 99, 866, 764, 766, 287, 87, 221, 995, 108, 769, 953, 412, 437, 29, 65, 263, 262, 354, 49, 584, 282, 519, 339, 855, 876, 13, 894, 89, 600, 836, 742, 313, 617, 789, 644, 775, 847, 981, 39, 872, 276, 7, 163, 639, 486, 567, 521, 399, 592, 224, 167, 93, 891, 241, 535, 258, 725, 485, 14, 733, 527, 702, 44, 965, 219, 469, 449, 687, 786, 365, 130, 377, 703, 444, 790, 483, 681, 309, 496, 435, 385, 838, 82, 136, 812, 38, 333, 755, 275, 529, 410, 976, 209, 2, 142, 808, 144, 90, 25, 878, 670, 711, 228, 580, 389, 614, 239, 728, 122, 608, 544, 674, 664, 398, 688, 863, 288, 559, 746, 668, 734, 924, 67, 915, 833, 26, 457, 595, 556, 80, 630, 730, 573, 386, 475, 839, 154, 546, 342, 233, 949, 930, 561, 623, 934, 458, 831, 793, 518, 52, 125, 778, 888, 660, 353, 964, 967, 86, 291, 501, 832, 520, 492, 613, 205, 848, 223, 980, 731, 849, 777, 176, 698, 252, 926, 446, 568, 514, 516, 442, 562, 97, 440, 610, 106, 294, 466, 84, 104, 783, 962, 191, 943, 620, 784, 661, 479, 585, 998, 937, 497, 218, 822, 253};
	
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  	printf("Input array is \n"); 
    printArray(arr, arr_size); 

	struct timespec tstart={0,0}, tend={0,0};
	
    clock_gettime(CLOCK_MONOTONIC, &tstart);
    quickSortMiddle(arr, 0,arr_size-1);
    //quickSortLastPivot(arr, 0,arr_size-1);
	clock_gettime(CLOCK_MONOTONIC, &tend);
	
    printf("\nSorted array with Quick Sort \n");
    printArray(arr, arr_size);
    
  
double elapsed;
    elapsed=(((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) -((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec))/100;

	printf("\nTime passed while running quick sort: %.15f	",elapsed ); 
}
