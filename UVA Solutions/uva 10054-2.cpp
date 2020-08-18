/**
 * Created by Aminul on 6/9/2018.
 */

import java.io.*;
import java.util.*;
import static java.lang.Math.*;

public class Main {
    public static void main(String[] args)throws Exception {
        FastReader in = new FastReader(System.in);
        PrintWriter pw = new PrintWriter(System.out);

        int test = in.nextInt();
        for(int t = 1; t <= test; t++) {
            int n = in.nextInt();
            int m = in.nextInt();
            List<Node> g[] = genList(100005);
            for (int i = 0; i < m; i++) {
                int u = in.nextInt(), v = in.nextInt();
                g[u].add(new Node(v, i));
                g[v].add(new Node(u, i));
            }


            List<Integer> e = eulerPathUndirected(g);
            pw.print("Case "+t+": ");
            if(e == null){
                pw.println("No");
            }
            else{
                pw.println("Yes");
            }

            //if(t < test) pw.println();
        }


        pw.close();
    }

    static <T>List<T>[] genList(int n){
        List<T> list[] = new List[100005];
        for(int i = 0; i < n; i++) list[i] = new ArrayList<T>();
        return list;
    }

    static class Node{
        int v, idx;
        Node(int V, int I){
            v = V; idx = I;
        }
    }

    public static List<Integer> eulerPathUndirected(List<Node>[] graph) {
        int u = -1, n = graph.length, edges = 0;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() > 0 && graph[i].size() % 2 == 0 && u == -1) {
                u = i;
            }
            if (graph[i].size() % 2 == 1) return null;
            edges += graph[i].size();
        }
        return eulerCycleUndirected(graph, u, edges/2);
    }


    public static List<Integer> eulerCycleUndirected(List<Node>[] graph, int u,  int edges) {
        int[] curEdge = new int[graph.length];
        List<Integer> res = new ArrayList<>();
        Stack<Integer> stack = new Stack<>();
        stack.add(u);
        boolean vis[] = new boolean[edges];
        while (!stack.isEmpty()) {
            u = stack.pop();
            while (curEdge[u] < graph[u].size()) {
                Node node = graph[u].get(curEdge[u]++);
                int v = node.v, id = node.idx;
                if (!vis[id]) {
                    stack.push(u);
                    u = v;
                    vis[id] = true;
                }
            }
            res.add(u);
        }

        if (res.size() != edges + 1) return null;

        Collections.reverse(res);
        return res;
    }



    static void debug(Object...obj) {
        System.err.println(Arrays.deepToString(obj));
    }

    static class FastReader {
        InputStream is;
        private byte[] inbuf = new byte[1024];
        private int lenbuf = 0, ptrbuf = 0;
        static final int ints[] = new int[128];

        public FastReader(InputStream is){
            for(int i='0';i<='9';i++) ints[i]=i-'0';
            this.is = is;
        }

        public int readByte(){
            if(lenbuf == -1)throw new InputMismatchException();
            if(ptrbuf >= lenbuf){
                ptrbuf = 0;
                try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
                if(lenbuf <= 0)return -1;
            }
            return inbuf[ptrbuf++];
        }

        public boolean isSpaceChar(int c) {
            return !(c >= 33 && c <= 126);
        }
        public int skip() {
            int b;
            while((b = readByte()) != -1 && isSpaceChar(b));
            return b;
        }

        public String next(){
            int b = skip();
            StringBuilder sb = new StringBuilder();
            while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public int nextInt(){
            int num = 0, b;
            boolean minus = false;
            while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
            if(b == '-'){
                minus = true;
                b = readByte();
            }

            while(true){
                if(b >= '0' && b <= '9'){
                    num = (num<<3) + (num<<1) + ints[b];
                }else{
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

        public long nextLong() {
            long num = 0;
            int b;
            boolean minus = false;
            while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
            if(b == '-'){
                minus = true;
                b = readByte();
            }

            while(true){
                if(b >= '0' && b <= '9'){
                    num = (num<<3) + (num<<1) + ints[b];
                }else{
                    return minus ? -num : num;
                }
                b = readByte();
            }
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
       /* public char nextChar() {
            return (char)skip();
        }*/

        public char[] next(int n){
            char[] buf = new char[n];
            int b = skip(), p = 0;
            while(p < n && !(isSpaceChar(b))){
                buf[p++] = (char)b;
                b = readByte();
            }
            return n == p ? buf : Arrays.copyOf(buf, p);
        }

        /*private char buff[] = new char[1005];
        public char[] nextCharArray(){
            int b = skip(), p = 0;
            while(!(isSpaceChar(b))){
                buff[p++] = (char)b;
                b = readByte();
            }
            return Arrays.copyOf(buff, p);
        }*/
    }
}
