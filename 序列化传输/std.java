import java.util.*;

class Main {
    static final int N = 1000010;

    static class Trie {
        int[][] tr = new int[N][2];
        int idx = 0;
        int[] cnt = new int[N];

        void insert(String s, int id) {
            int p = 0;
            for (char u : s.toCharArray()) {
                int ch = u - '0';
                if (tr[p][ch] == 0)
                    tr[p][ch] = ++idx;
                p = tr[p][ch];
                cnt[p]++;
            }
        }

        int query(String s) {
            int p = 0;
            int len = 0;
            for (char u : s.toCharArray()) {
                int ch = u - '0';
                if (tr[p][ch] != 0) {
                    p = tr[p][ch];
                    len++;
                } else {
                    break;
                }
            }
            return len;
        }

        void remove(String s) {
            int p = 0;
            for (char u : s.toCharArray()) {
                int ch = u - '0';
                int tmp = tr[p][ch];
                cnt[tr[p][ch]]--;
                if (cnt[tr[p][ch]] == 0) {
                    tr[p][ch] = 0;
                }
                p = tmp;
            }
        }
    }

    static String Hex2Proto(String s) {
        StringBuilder res = new StringBuilder();
        for (int i = 2; i < s.length(); ++i) {
            int num = 0;
            if (Character.isDigit(s.charAt(i))) {
                num = s.charAt(i) - '0';
            } else {
                num = s.charAt(i) - 'A' + 10;
            }
            StringBuilder tmp = new StringBuilder();
            for (int j = 0; j < 4; ++j) {
                tmp.append('0' + (num & 1));
                num >>= 1;
            }
            res.append(tmp.reverse());
        }
        return res.toString();
    }

    static String Proto2Binary(String s) {
        StringBuilder res = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i -= 8) {
            for (int j = i - 6; j <= i; ++j) {
                res.append(s.charAt(j));
            }
        }
        res.reverse();
        while (res.length() > 0 && res.charAt(res.length() - 1) == '0') {
            res.deleteCharAt(res.length() - 1);
        }
        res.reverse();
        return res.toString();
    }

    static void solve() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        List<String> vec = new ArrayList<>();
        vec.add("0");

        int idx = 0;
        int s = 0;

        Map<String, Integer> mp = new HashMap<>();

        while (n-- > 0) {
            int x = sc.nextInt();
            String y = sc.next();

            if (x == 1) {
                mp.put(y, mp.getOrDefault(y, 0) + 1);
                String Proto_y = Hex2Proto(y);
                String Binary_y = Proto2Binary(Proto_y);

                s = T.query(Binary_y);
                T.insert(Binary_y, ++idx);
                vec.add(Binary_y);

                System.out.println(mp.get(y) + " " + s);
            } else {
                if (mp.containsKey(y) && mp.get(y) > 0) {
                    mp.put(y, mp.get(y) - 1);
                    String Proto_y = Hex2Proto(y);
                    String Binary_y = Proto2Binary(Proto_y);
                    T.remove(Binary_y);
                }
            }
        }

        sc.close();
    }

    public static void main(String[] args) {
        Trie T = new Trie();
        solve();
    }
}
