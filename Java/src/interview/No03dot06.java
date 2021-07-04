/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package interview;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class No03dot06 {
    static class AnimalShelf {
        private List<int[]> catList;
        private List<int[]> dogList;
        int counter = 0;

        public AnimalShelf() {
            catList = new LinkedList<>();
            dogList = new LinkedList<>();
        }

        public void enqueue(int[] animal) {
            if (animal[1] == 0) catList.add(new int[]{animal[0], counter++});
            else dogList.add(new int[]{animal[0], counter++});
        }

        public int[] dequeueAny() {
            int[] dog = dogList.isEmpty() ? null : dogList.get(0);
            int[] cat = catList.isEmpty() ? null : catList.get(0);
            if (dog == null && cat == null) return new int[]{-1, -1};
            if (dog == null) {
                catList.remove(0);
                return new int[]{cat[0], 0};
            } else if (cat == null) {
                dogList.remove(0);
                return new int[]{dog[0], 1};
            } else if (dog[1] < cat[1]) {
                dogList.remove(0);
                return new int[]{dog[0], 1};
            } else {
                catList.remove(0);
                return new int[]{cat[0], 0};
            }
        }

        public int[] dequeueDog() {
            int[] dog = dogList.isEmpty() ? null : dogList.get(0);
            if (dog != null) dogList.remove(0);
            return dog == null ? new int[]{-1, -1} : new int[]{dog[0], 1};
        }

        public int[] dequeueCat() {
            int[] cat = catList.isEmpty() ? null : catList.get(0);
            if (cat != null) catList.remove(0);
            return cat == null ? new int[]{-1, -1} : new int[]{cat[0], 0};
        }
    }

    public static void main(String[] args) {
        AnimalShelf animalShelf = new AnimalShelf();
        animalShelf.enqueue(new int[]{0, 0});
        animalShelf.enqueue(new int[]{1, 0});
        System.out.println(Arrays.toString(animalShelf.dequeueCat()));
        System.out.println(Arrays.toString(animalShelf.dequeueDog()));
        System.out.println(Arrays.toString(animalShelf.dequeueAny()));
    }
}
