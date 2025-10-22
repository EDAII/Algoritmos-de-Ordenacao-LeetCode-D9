// Implementação otimizada para o problema 75 do leetcode
void sortColors(int* nums, int numsSize) {
    int ini = 0, meio = 0;
    int fim = numsSize -1;
    int temp;

    while(meio <= fim){
        if(nums[meio] == 0){
            temp = nums[ini];
            nums[ini] = nums[meio];
            nums[meio] = temp;
            ini++;
            meio++;
        }
        else if(nums[meio] == 1) {
            meio++;
        }
        else if(nums[meio] == 2){
            temp = nums[fim];
            nums[fim] = nums[meio];
            nums[meio] = temp;
            fim--;
        }

    }

}