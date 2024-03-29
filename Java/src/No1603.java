/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */
class ParkingSystem {
    private int big, medium, small;

    public ParkingSystem(int big, int medium, int small) {
        this.big = big;
        this.medium = medium;
        this.small = small;
    }

    public boolean addCar(int carType) {
        switch (carType) {
            case 1:
                return --big >= 0;
            case 2:
                return --medium >= 0;
            case 3:
                return --small >= 0;
        }
        return false;
    }
}

public class No1603 {
}
