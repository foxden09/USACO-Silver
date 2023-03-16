import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringJoiner;
import java.util.StringTokenizer;
 
public class ArrayDifferences {
 
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        int[][] differences = new int[n][n];
        for (int j = 0; j < n; j++) {
            StringTokenizer tokenizer = new StringTokenizer(in.readLine());
            for (int k = j; k < n; k++) {
                differences[j][k] = Integer.parseInt(tokenizer.nextToken());
            }
        }
        List<Integer> distinct = new ArrayList<>();
        distinct.add(0);
        for (int j = 1; j < n; j++) {
            if (differences[j - 1][j] != 0) {
                distinct.add(j);
            }
        }
        int[] answer = new int[n];
        if (distinct.size() > 1) {
            answer[distinct.get(1)] = differences[0][distinct.get(1)];
            for (int j = 2; j < distinct.size(); j++) {
                int a = distinct.get(j - 2);
                int b = distinct.get(j - 1);
                int c = distinct.get(j);
                int sign = differences[a][c] == differences[a][b] + differences[b][c] ? 1 : -1;
                answer[c] = answer[b] + (sign * Integer.signum(answer[b] - answer[a]) * differences[b][c]);
            }
            for (int j = 1; j < n; j++) {
                if (differences[j - 1][j] == 0) {
                    answer[j] = answer[j - 1];
                }
            }
        }
        StringJoiner joiner = new StringJoiner(" ");
        for (int j = 0; j < n; j++) {
            joiner.add("" + answer[j]);
        }
        System.out.println(joiner);
    }
}