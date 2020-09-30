/*
题目：第k个排列
题目思路：从首位到末位依次算出

不熟练：List初始化
*/
class Solution {
    public String getPermutation(int n, int k) {
        int sum = 1;
        String ret = "";
        
        List<String> list = new ArrayList<>();
        for (int i = 2;i < n;i++) {
            sum *= i;
        }

        for (int i = 1;i <= n;i++) {
            list.add(i+"");
        }

        while (n != 1) {
            ret = ret + list.get((k-1) / sum);
            list.remove((k-1) / sum);
            n = n - 1;
            k = (k % sum)==0?sum:k%sum;
            sum = sum / n;
        }
        ret = ret + list.get(0);
        return ret;
    }
}