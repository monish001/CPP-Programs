#include<iostream>
#include<map>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include <climits>
#include <cmath>
using namespace std;

#define ll long long
#define pii pair<int,int>

//int Solution::repeatedNumber(const vector<int> &A) {
int repeatedNumber(const vector<int> &A) {
    int len = A.size();
    int MAX_N = len-1;
    double dSqrtN = sqrt(MAX_N);
    int sqrtN = sqrt(MAX_N);
    int bucketCount = sqrtN*sqrtN == MAX_N ? sqrtN : sqrtN+1; // bucketCount buckets for each to have bucketCount number of elements max
    vector<int> count(bucketCount, 0);
    int faultyBucketIndex = (MAX_N-1)/bucketCount;
    for(int index=0; index<len; index++){
        int num = A[index];
        if(num < 1 || num > MAX_N){
            cout<<"Invalid input"<<endl;
            return -1;
        }
        int bucketIndex = (num-1)/bucketCount;
		if(bucketIndex >= bucketCount){
			cout<<"Error: index out of bounds for bucketIndex:"<<bucketIndex<<", bucketCount:"<<bucketCount<<", num: "<<num<<"."<<endl;
		}
        count[bucketIndex]++;
//cout<<"bucketIndex:"<<bucketIndex<<", bucketCount:"<<bucketCount<<", num: "<<num<<", Num of elements in this bucket:"<<count[bucketIndex]<<endl;
        if(count[bucketIndex] > bucketCount){ // each bucket should contain max bucketCount elements for things to be fine
            faultyBucketIndex = bucketIndex;
            break;
        }
    }
//cout<<"Faulty bucket index: "<<faultyBucketIndex<<endl;

    for(int index = 0; index<bucketCount; index++){
        count[index] = 0;
    }

    for(int index=0; index<len; index++){
        int bucketIndex = (A[index]-1)/bucketCount;
        if(bucketIndex==faultyBucketIndex){
            int indexInBucket = A[index]%bucketCount;
//cout<<"Index for "<<A[index]<<" in faulty bucket is "<<indexInBucket<<endl;
			if(indexInBucket >= bucketCount){
//cout<<"Error: index out of bounds. 2"<<endl;
			}
            if(count[indexInBucket] == 1){
                return A[index];
            }
//cout<<"IndexInBucket:"<<indexInBucket<<"\t"<<"Size:"<<bucketCount<<endl;
            count[indexInBucket]++;
        }
    }
    cout<<"Invalid input, no repeated number detected."<<endl;
}

int main()
{
    int len;
    int x[] = {247, 240, 303, 9, 304, 105, 44, 204, 291, 26, 242, 2, 358, 264, 176, 289, 196, 329, 189, 102, 45, 111, 115, 339, 74, 200, 34, 201, 215, 173, 107, 141, 71, 125, 6, 241, 275, 88, 91, 58, 171, 346, 219, 238, 246, 10, 118, 163, 287, 179, 123, 348, 283, 313, 226, 324, 203, 323, 28, 251, 69, 311, 330, 316, 320, 312, 50, 157, 342, 12, 253, 180, 112, 90, 16, 288, 213, 273, 57, 243, 42, 168, 55, 144, 131, 38, 317, 194, 355, 254, 202, 351, 62, 80, 134, 321, 31, 127, 232, 67, 22, 124, 271, 231, 162, 172, 52, 228, 87, 174, 307, 36, 148, 302, 198, 24, 338, 276, 327, 150, 110, 188, 309, 354, 190, 265, 3, 108, 218, 164, 145, 285, 99, 60, 286, 103, 119, 29, 75, 212, 290, 301, 151, 17, 147, 94, 138, 272, 279, 222, 315, 116, 262, 1, 334, 41, 54, 208, 139, 332, 89, 18, 233, 268, 7, 214, 20, 46, 326, 298, 101, 47, 236, 216, 359, 161, 350, 5, 49, 122, 345, 269, 73, 76, 221, 280, 322, 149, 318, 135, 234, 82, 120, 335, 98, 274, 182, 129, 106, 248, 64, 121, 258, 113, 349, 167, 192, 356, 51, 166, 77, 297, 39, 305, 260, 14, 63, 165, 85, 224, 19, 27, 177, 344, 33, 259, 292, 100, 43, 314, 170, 97, 4, 78, 310, 61, 328, 199, 255, 159, 185, 261, 229, 11, 295, 353, 186, 325, 79, 142, 223, 211, 152, 266, 48, 347, 21, 169, 65, 140, 83, 156, 340, 56, 220, 130, 117, 143, 277, 235, 59, 205, 153, 352, 300, 114, 84, 183, 333, 230, 197, 336, 244, 195, 37, 23, 206, 86, 15, 187, 181, 308, 109, 293, 128, 66, 270, 209, 158, 32, 25, 227, 191, 35, 40, 13, 175, 146, 299, 207, 217, 281, 30, 357, 184, 133, 245, 284, 343, 53, 210, 306, 136, 132, 239, 155, 73, 193, 278, 257, 126, 331, 294, 250, 252, 263, 92, 267, 282, 72, 95, 337, 154, 319, 341, 70, 81, 68, 160, 8, 249, 96, 104, 137, 256, 93, 178, 296, 225, 237};
    len = sizeof x / sizeof x[0];
    vector<int> vec(x, x + len);

    int x1[] = {3,2,1,3};
    int len1 = sizeof x1 / sizeof x1[0];
    vector<int> vec1(x1, x1 + len1);

    int x2[] = {400, 482, 128, 693, 274, 403, 454, 429, 701, 661, 450, 669, 338, 383, 199, 365, 472, 148, 511, 56, 98, 412, 684, 162, 378, 570, 59, 58, 565, 402, 214, 681, 195, 303, 485, 675, 555, 685, 518, 2, 101, 459, 622, 332, 306, 164, 109, 222, 360, 35, 425, 362, 612, 486, 212, 305, 604, 467, 537, 6, 687, 682, 8, 178, 333, 465, 443, 667, 90, 569, 705, 249, 115, 678, 597, 563, 606, 611, 438, 356, 366, 582, 468, 595, 388, 628, 539, 623, 578, 189, 184, 692, 94, 108, 166, 420, 492, 358, 507, 603, 448, 34, 394, 426, 207, 503, 557, 435, 292, 17, 163, 564, 176, 508, 24, 12, 28, 589, 381, 276, 233, 442, 633, 197, 605, 359, 91, 596, 657, 273, 111, 31, 291, 21, 520, 462, 245, 33, 373, 363, 447, 703, 29, 469, 105, 186, 350, 413, 416, 498, 364, 22, 651, 253, 330, 142, 471, 54, 14, 652, 670, 463, 82, 314, 138, 473, 175, 647, 382, 152, 220, 501, 310, 515, 160, 377, 650, 280, 551, 267, 531, 391, 663, 389, 571, 63, 15, 100, 646, 123, 417, 643, 258, 458, 325, 136, 696, 78, 629, 318, 559, 84, 36, 586, 209, 16, 70, 584, 234, 423, 554, 393, 147, 224, 210, 474, 294, 446, 625, 672, 466, 288, 221, 38, 710, 644, 55, 219, 10, 203, 396, 452, 484, 414, 315, 704, 714, 280, 62, 296, 126, 581, 134, 590, 326, 702, 686, 228, 543, 440, 386, 422, 49, 352, 553, 372, 620, 329, 547, 97, 639, 341, 309, 64, 27, 165, 157, 392, 509, 188, 690, 406, 626, 241, 301, 317, 88, 122, 630, 232, 312, 699, 137, 39, 430, 536, 470, 525, 154, 285, 659, 324, 140, 193, 346, 577, 664, 183, 437, 624, 572, 368, 289, 40, 401, 548, 424, 409, 456, 229, 230, 237, 73, 506, 478, 255, 419, 343, 113, 194, 455, 89, 574, 208, 76, 110, 131, 227, 61, 180, 41, 172, 434, 331, 235, 656, 23, 145, 265, 327, 268, 295, 151, 638, 695, 544, 278, 182, 449, 81, 535, 223, 283, 541, 579, 618, 592, 344, 369, 215, 648, 196, 483, 293, 613, 263, 637, 298, 593, 247, 428, 25, 68, 683, 490, 588, 334, 217, 96, 561, 190, 556, 319, 713, 530, 694, 7, 238, 552, 26, 642, 192, 355, 488, 408, 174, 398, 248, 139, 407, 375, 106, 95, 676, 50, 550, 439, 598, 532, 18, 594, 502, 522, 80, 69, 505, 627, 252, 75, 250, 361, 231, 549, 340, 271, 339, 481, 404, 635, 433, 666, 453, 321, 494, 587, 53, 526, 475, 32, 345, 20, 328, 92, 493, 135, 46, 347, 168, 103, 527, 170, 521, 445, 239, 510, 266, 181, 284, 169, 418, 616, 107, 476, 30, 191, 480, 216, 399, 277, 300, 74, 218, 621, 689, 349, 225, 660, 177, 37, 251, 279, 187, 205, 286, 545, 87, 436, 658, 654, 198, 602, 519, 609, 246, 337, 600, 125, 708, 158, 213, 112, 127, 202, 528, 311, 287, 206, 99, 461, 491, 79, 155, 619, 121, 411, 66, 698, 67, 320, 641, 322, 226, 129, 342, 308, 9, 464, 281, 384, 304, 119, 631, 653, 185, 427, 11, 48, 130, 240, 390, 514, 282, 200, 645, 149, 387, 499, 560, 451, 512, 567, 691, 410, 546, 116, 504, 385, 668, 167, 460, 583, 634, 201, 607, 146, 71, 679, 370, 270, 299, 120, 353, 57, 376, 496, 302, 688, 479, 516, 141, 395, 19, 706, 351, 367, 354, 523, 269, 52, 680, 599, 72, 118, 489, 573, 242, 632, 674, 566, 477, 529, 562, 42, 236, 495, 444, 259, 671, 677, 662, 655, 204, 297, 487, 558, 524, 540, 86, 171, 161, 264, 379, 336, 143, 102, 133, 335, 153, 51, 4, 421, 262, 374, 615, 432, 580, 256, 397, 132, 673, 3, 83, 538, 114, 13, 261, 709, 316, 47, 497, 500, 43, 617, 665, 260, 636, 85, 357, 712, 243, 568, 150, 513, 614, 441, 576, 156, 93, 254, 323, 517, 77, 585, 371, 534, 405, 124, 380, 179, 211, 117, 159, 173, 608, 272, 1, 575, 65, 711, 45, 700, 257, 60, 431, 640, 610, 5, 533, 44, 415, 591, 290, 649, 144, 457, 104, 275, 601, 707, 307, 348, 313, 697, 244, 542};
    int len2 = sizeof x2 / sizeof x2[0];
    vector<int> vec2(x2, x2 + len2);

    int x3[] = {127, 228, 308, 341, 350, 371, 195, 11, 223, 138, 206, 279, 385, 289, 276, 152, 42, 208, 382, 22, 185, 339, 64, 149, 337, 122, 101, 15, 388, 205, 160, 35, 277, 240, 201, 302, 335, 336, 61, 236, 320, 200, 85, 44, 287, 164, 50, 366, 202, 301, 259, 89, 59, 113, 47, 248, 146, 71, 23, 373, 197, 39, 27, 381, 219, 253, 32, 386, 129, 105, 299, 296, 31, 110, 151, 191, 372, 395, 255, 257, 275, 77, 380, 226, 90, 251, 67, 281, 234, 9, 30, 216, 370, 1, 88, 107, 10, 368, 80, 119, 34, 325, 82, 328, 54, 319};
    int len3 = sizeof x3 / sizeof x3[0];
    vector<int> vec3(x3, x3 + len3);

    int x4[] = {442, 249, 406, 112, 202, 98, 228, 99, 38, 10, 402, 505, 104, 340, 265, 317, 190, 403, 148, 276, 145, 199, 456, 489, 237, 226, 470, 342, 405, 339, 142, 234, 542, 96, 71, 297, 261, 262, 130, 119, 428, 82, 432, 219, 430, 439, 188, 397, 227, 478, 400, 111, 451, 388, 34, 303, 158, 68, 74, 502, 36, 80, 243, 508, 73, 324, 103, 325, 46, 211, 133, 144, 480, 404, 231, 416, 401, 370, 3, 48, 407, 195, 212, 300, 47, 409, 44, 21, 248, 105, 56, 319, 117, 149, 334, 455, 544, 429, 464, 143, 75, 197, 316, 292, 352, 282, 525, 194, 87, 242, 283, 333, 356, 440, 338, 100, 366, 368, 520, 129, 479, 499, 408, 496, 307, 173, 347, 101, 293, 523, 114, 5, 393, 178, 329, 394, 302, 59, 492, 175, 537, 538, 454, 217, 84, 344, 126, 360, 471, 433, 238, 465, 62, 165, 43, 139, 530, 512, 280, 312, 518, 385, 8, 29, 93, 467, 320, 64, 120, 452, 391, 358, 522, 445, 274, 240, 172, 449, 205, 18, 328, 453, 278, 536, 69, 331, 166, 92, 50, 462, 501, 27, 106, 72, 30, 11, 289, 318, 343, 245, 497, 411, 218, 363, 151, 85, 37, 337, 285, 511, 137, 426, 155, 254, 376, 136, 235, 90, 418, 60, 487, 181, 232, 486, 287, 515, 362, 86, 395, 255, 159, 527, 336, 378, 375, 115, 15, 179, 33, 67, 177, 247, 51, 424, 284, 357, 157, 162, 253, 135, 216, 122, 41, 118, 359, 209, 355, 373, 437, 23, 214, 97, 191, 447, 83, 267, 256, 20, 52, 236, 39, 259, 204, 353, 510, 55, 203, 305, 290, 206, 413, 488, 14, 380, 174, 540, 299, 463, 485, 371, 309, 186, 481, 192, 200, 156, 288, 534, 475, 382, 184, 152, 220, 189, 521, 443, 110, 160, 369, 171, 183, 468, 65, 108, 427, 423, 516, 146, 384, 138, 222, 35, 365, 163, 458, 132, 498, 372, 66, 345, 326, 396, 40, 141, 22, 491, 19, 286, 415, 434, 121, 1, 270, 313, 78, 446, 379, 392, 31, 9, 180, 420, 45, 76, 26, 460, 49, 89, 279, 54, 57, 208, 519, 241, 275, 386, 441, 533, 296, 507, 422, 109, 196, 361, 2, 4, 474, 182, 53, 310, 414, 291, 364, 61, 535, 398, 134, 24, 509, 335, 484, 263, 476, 154, 304, 25, 306, 444, 32, 266, 210, 539, 473, 322, 7, 466, 529, 436, 350, 494, 16, 161, 116, 459, 168, 301, 215, 213, 91, 438, 102, 224, 277, 13, 17, 28, 258, 70, 531, 541, 532, 315, 187, 381, 170, 272, 147, 223, 252, 421, 81, 271, 201, 164, 176, 58, 257, 321, 95, 377, 472, 113, 94, 457, 153, 469, 225, 140, 399, 281, 308, 230, 193, 390, 514, 483, 412, 327, 12, 543, 367, 493, 504, 419, 524, 198, 77, 295, 417, 389, 374, 435, 42, 330, 528, 311, 490, 387, 341, 517, 127, 298, 169, 185, 125, 233, 410, 477, 128, 239, 107, 448, 354, 221, 425, 264, 294, 323, 88, 526, 124, 351, 349, 506, 150, 348, 246, 482, 260, 251, 167, 503, 250, 268, 273, 207, 540, 332, 63, 431, 131, 383, 6, 495, 244, 346, 269, 79, 450, 513, 123, 461, 314, 229, 500};
    int len4 = sizeof x4 / sizeof x4[0];
    vector<int> vec4(x4, x4 + len4);

    int result = repeatedNumber(vec);
    //cout<<"size:"<<len4<<endl;
    cout<<result<<"\t";
    return 0;
}
