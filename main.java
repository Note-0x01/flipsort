package com.flipsort;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class main {
    public static void main(String[] args) {
        int[] x = {3,2,4,1};
        System.out.println("Input");
        for(int val: x)
            System.out.print(val + " ");
        System.out.print("\n");
        Pair<int[], List<Integer>> sorted = flipSort(x);
        System.out.println("Finished Sort");
        for(int val: sorted.a)
            System.out.print(val + " ");
        System.out.print("\n");
        System.out.println("k Values");
        for(int val: sorted.b)
            System.out.print(val + " ");
        System.out.print("\n");
    }

    static Pair<int[], List<Integer>> flipSort(int[] arr) {
        List<Integer> kValues = new ArrayList<Integer>();
        int[] flip = Arrays.copyOf(arr, arr.length);
        for(int arrLength = flip.length; arrLength > 1; --arrLength) {
            int max = 0, mIndex = 0;
            for(int i = 0; i < arrLength; i++) {
                if(flip[i] > max) {
                    max = flip[i];
                    mIndex = i;
                }
            }

            if(mIndex != (arrLength - 1)) {
                if (mIndex != 0) {
                    partialFlip(flip, mIndex);
                    kValues.add(mIndex);
                }

                partialFlip(flip, arrLength-1);
                kValues.add(arrLength-1);
            }
        }

        return new Pair<>(flip, kValues);
    }

    static int[] partialFlip(int[] arr, int k) {
        int valAtI;
        for(int i = 0; i <= k / 2; i++) {
            valAtI = arr[i];
            arr[i] = arr[(k - i)];
            arr[(k - i)] = valAtI;
        }
        return arr;
    }

    public static class Pair<A,B> {
        public final A a;
        public final B b;

        public Pair(A a, B b) {
            this.a = a;
            this.b = b;
        }
    };
}
