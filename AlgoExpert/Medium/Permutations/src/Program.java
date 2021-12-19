import java.util.*;

class Program {
    public static List<List<Integer>> getPermutationsBAckTracking(List<Integer> array) {
        List<List<Integer>> retList = new ArrayList<>();
        permutationsHelper(0, array, retList);
        return retList;
    }

    public static void permutationsHelper(int i, List<Integer> array, List<List<Integer>> permutations) {
        // If we have already reached the end of the array, capture it into our perms list
        if (i == array.size() - 1)
            permutations.add(new ArrayList<>(array));
        else {
            for (int j = i; j < array.size(); j++) {
                Collections.swap(array, i, j);
                permutationsHelper(i + 1, array, permutations);
                Collections.swap(array, i, j);
            }
        }
    }

    public static List<List<Integer>> getPermutations(List<Integer> list) {
        List<List<Integer>> retList = new ArrayList<>();
        if (list.size() == 1) {
            List<Integer> l2 = new ArrayList<>();
            l2.add(list.get(0));
            retList.add(l2);
        }
        // If there are only two elements, return the two combos of them.
        else if (list.size() == 2) {
            List<Integer> l1 = new ArrayList<>();
            l1.add(list.get(0));
            l1.add(list.get(1));

            List<Integer> l2 = new ArrayList<>();
            l2.add(list.get(1));
            l2.add(list.get(0));

            retList.add(l1);
            retList.add(l2);
        } else {
            // Otherwise, recursively call the method in suc a way that you remove one element from the list and pass the remaining elements to the function to get their permutations
            // And append back the element to the result at the front
            for (int i = 0; i < list.size(); i++) {
                int fixedEle = list.get(i);
                List<Integer> remEle = new ArrayList<>();
                for (int j = 0; j < list.size(); j++) {
                    if (j == i)
                        continue;
                    remEle.add(list.get(j));
                }
                List<List<Integer>> tempResList = getPermutations(remEle);
                tempResList.forEach(list1 -> list1.add(0, fixedEle));
                retList.addAll(tempResList);
            }
        }
        return retList;
    }

    public static void main(String[] args) {
        getPermutationsBAckTracking(Arrays.asList(1,2,3)).forEach(list -> {
            for (int i : list) {
                System.out.print(i + " ");
            }
            System.out.println();
        });
    }
}
