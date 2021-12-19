public class SpacesString {
    public String addSpaces(String s, int[] spaces) {
        int count = 0;
        StringBuilder bldr = new StringBuilder(s);
        for (int space : spaces) {
            bldr.insert(space + count, ' ');
            count++;
        }
        return bldr.toString();
    }

    public static void main(String[] args) {
        SpacesString ss = new SpacesString();
        System.out.println(ss.addSpaces("LeetcodeHelpsMeLearn", new int[]{8, 13, 15}));
    }
}
