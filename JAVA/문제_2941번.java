import java.util.*;
import java.io.*;

public class Main{
    public static void main(String arg[])throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String str = br.readLine();
        int result = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == 'c') {
                if (i + 1 < str.length() && (str.charAt(i + 1) == '=' || str.charAt(i + 1) == '-')) {
                    result++;
                    i++;
                } else
                    result++;
            } else if (str.charAt(i) == 'd') {
                if (i + 1 < str.length() && str.charAt(i + 1) == '-') {
                    result++;
                    i++;
                } else if (i + 2 < str.length() && str.charAt(i + 1) == 'z' && str.charAt(i + 2) == '=') {
                    result++;
                    i += 2;
                } else
                    result++;
            } else if (i + 1 < str.length()) {
                if (str.charAt(i) == 'l' && str.charAt(i + 1) == 'j') {
                    result++;
                    i++;
                } else if (str.charAt(i) == 'n' && str.charAt(i + 1) == 'j') {
                    result++;
                    i++;
                } else if (str.charAt(i) == 's' && str.charAt(i + 1) == '=') {
                    result++;
                    i++;
                } else if (str.charAt(i) == 'z' && str.charAt(i + 1) == '=') {
                    result++;
                    i++;
                }
                else
                    result++;
            } else
                result++;
        }
        System.out.println(result);
    }
}