/*
 * Copyright (c) 2021, HuXiaozhong. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 */

package weeklyContest246;

public class No2 {
    public int numberOfRounds(String startTime, String finishTime) {
        int startH = Integer.parseInt(startTime.split(":")[0]);
        int startM = Integer.parseInt(startTime.split(":")[1]);
        int finishH = Integer.parseInt(finishTime.split(":")[0]);
        int finishM = Integer.parseInt(finishTime.split(":")[1]);
        int hours = 0;
        int minutes = 0;
        if (finishH < startH || (finishH == startH && startM > finishM)) hours = finishH + 24 - startH;
        else hours = finishH - startH;
        minutes =  finishM / 15 - (startM + 14) / 15;
        int ans = hours * 4 + minutes;
        return ans;
    }

    public static void main(String[] args) {
        No2 no2 = new No2();
        System.out.println(no2.numberOfRounds("12:01", "12:02"));
    }
}
