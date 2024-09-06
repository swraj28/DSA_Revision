package com.thealgorithms.Leetcode;

import java.util.HashMap;
import java.util.Map;

class Solution_1 {

    public String numberToWords(int num) {
        int cntr = 0;
        String ans1 = "", ans2 = "", ans3 = "", ans4 = "";

        Map<String, String> m = new HashMap<>();

        m.put("1", "One");
        m.put("2", "Two");
        m.put("3", "Three");
        m.put("4", "Four");
        m.put("5", "Five");
        m.put("6", "Six");
        m.put("7", "Seven");
        m.put("8", "Eight");
        m.put("9", "Nine");

        m.put("01", "One");
        m.put("02", "Two");
        m.put("03", "Three");
        m.put("04", "Four");
        m.put("05", "Five");
        m.put("06", "Six");
        m.put("07", "Seven");
        m.put("08", "Eight");
        m.put("09", "Nine");
        m.put("10", "Ten");
        m.put("11", "Eleven");
        m.put("12", "Twelve");
        m.put("13", "Thirteen");
        m.put("14", "Fourteen");
        m.put("15", "Fifteen");
        m.put("16", "Sixteen");
        m.put("17", "Seventeen");
        m.put("18", "Eighteen");
        m.put("19", "Nineteen");

        m.put("20", "Twenty");
        m.put("21", "Twenty One");
        m.put("22", "Twenty Two");
        m.put("23", "Twenty Three");
        m.put("24", "Twenty Four");
        m.put("25", "Twenty Five");
        m.put("26", "Twenty Six");
        m.put("27", "Twenty Seven");
        m.put("28", "Twenty Eight");
        m.put("29", "Twenty Nine");

        m.put("30", "Thirty");
        m.put("31", "Thirty One");
        m.put("32", "Thirty Two");
        m.put("33", "Thirty Three");
        m.put("34", "Thirty Four");
        m.put("35", "Thirty Five");
        m.put("36", "Thirty Six");
        m.put("37", "Thirty Seven");
        m.put("38", "Thirty Eight");
        m.put("39", "Thirty Nine");

        m.put("40", "Forty");
        m.put("41", "Forty One");
        m.put("42", "Forty Two");
        m.put("43", "Forty Three");
        m.put("44", "Forty Four");
        m.put("45", "Forty Five");
        m.put("46", "Forty Six");
        m.put("47", "Forty Seven");
        m.put("48", "Forty Eight");
        m.put("49", "Forty Nine");

        m.put("50", "Fifty");
        m.put("51", "Fifty One");
        m.put("52", "Fifty Two");
        m.put("53", "Fifty Three");
        m.put("54", "Fifty Four");
        m.put("55", "Fifty Five");
        m.put("56", "Fifty Six");
        m.put("57", "Fifty Seven");
        m.put("58", "Fifty Eight");
        m.put("59", "Fifty Nine");

        m.put("60", "Sixty");
        m.put("61", "Sixty One");
        m.put("62", "Sixty Two");
        m.put("63", "Sixty Three");
        m.put("64", "Sixty Four");
        m.put("65", "Sixty Five");
        m.put("66", "Sixty Six");
        m.put("67", "Sixty Seven");
        m.put("68", "Sixty Eight");
        m.put("69", "Sixty Nine");

        m.put("70", "Seventy");
        m.put("71", "Seventy One");
        m.put("72", "Seventy Two");
        m.put("73", "Seventy Three");
        m.put("74", "Seventy Four");
        m.put("75", "Seventy Five");
        m.put("76", "Seventy Six");
        m.put("77", "Seventy Seven");
        m.put("78", "Seventy Eight");
        m.put("79", "Seventy Nine");

        m.put("80", "Eighty");
        m.put("81", "Eighty One");
        m.put("82", "Eighty Two");
        m.put("83", "Eighty Three");
        m.put("84", "Eighty Four");
        m.put("85", "Eighty Five");
        m.put("86", "Eighty Six");
        m.put("87", "Eighty Seven");
        m.put("88", "Eighty Eight");
        m.put("89", "Eighty Nine");

        m.put("90", "Ninety");
        m.put("91", "Ninety One");
        m.put("92", "Ninety Two");
        m.put("93", "Ninety Three");
        m.put("94", "Ninety Four");
        m.put("95", "Ninety Five");
        m.put("96", "Ninety Six");
        m.put("97", "Ninety Seven");
        m.put("98", "Ninety Eight");
        m.put("99", "Ninety Nine");

        Map<String, String> m1 = new HashMap<>();
        m1.put("1", "One Hundred");
        m1.put("2", "Two Hundred");
        m1.put("3", "Three Hundred");
        m1.put("4", "Four Hundred");
        m1.put("5", "Five Hundred");
        m1.put("6", "Six Hundred");
        m1.put("7", "Seven Hundred");
        m1.put("8", "Eight Hundred");
        m1.put("9", "Nine Hundred");

        int temp_val = 0;
        String val = "";

        while (num > 0) {

            if (temp_val > 2) {
                temp_val = 0;

                val = new StringBuilder(val).reverse().toString();

                String temp_ans = "";

                if (val.length() == 3 && !val.substring(0, 1).equals("0")) {
                    temp_ans += m1.get(val.substring(0, 1));
                }

                if (!val.substring(1).equals("00")) {
                    if (!temp_ans.isEmpty()) {
                        temp_ans += " ";
                    }
                    temp_ans += m.get(val.substring(1));
                }

                if (cntr == 0) {
                    ans1 = temp_ans;
                } else if (cntr == 1) {
                    if (!temp_ans.isEmpty()) {
                        temp_ans += " ";
                        temp_ans += "Thousand";
                    }
                    ans2 = temp_ans;
                } else if (cntr == 2) {
                    if (!temp_ans.isEmpty()) {
                        temp_ans += " ";
                        temp_ans += "Million";
                    }
                    ans3 = temp_ans;
                } else if (cntr == 3) {
                    if (!temp_ans.isEmpty()) {
                        temp_ans += " ";
                        temp_ans += "Billion";
                    }
                    ans4 = temp_ans;
                }

                cntr++;
                val = "";
            }

            int x = num % 10;
            num /= 10;

            temp_val++;

            val += x;
        }

        if (!val.isEmpty()) {

            val = new StringBuilder(val).reverse().toString();

            String temp_ans = "";

            if (val.length() == 3 && !val.substring(0, 1).equals("0")) {
                temp_ans += m1.get(val.substring(0, 1));
            }

            if (val.length() == 3 && !val.substring(1).equals("00")) {
                temp_ans += " ";
                temp_ans += m.get(val.substring(1));
            }

            if (val.length() < 3) {
                temp_ans += m.get(val);
            }

            if (cntr == 0) {
                ans1 = temp_ans;
            } else if (cntr == 1) {
                temp_ans += " ";
                temp_ans += "Thousand";
                ans2 = temp_ans;
            } else if (cntr == 2) {
                temp_ans += " ";
                temp_ans += "Million";
                ans3 = temp_ans;
            } else if (cntr == 3) {
                temp_ans += " ";
                temp_ans += "Billion";
                ans4 = temp_ans;
            }
        }

        String ans = "";

        if (!ans4.isEmpty()) {
            ans += ans4;
        }

        if (!ans3.isEmpty()) {
            if (!ans.isEmpty()) {
                ans += " ";
            }
            ans += ans3;
        }

        if (!ans2.isEmpty()) {
            if (!ans.isEmpty()) {
                ans += " ";
            }
            ans += ans2;
        }

        if (!ans1.isEmpty()) {
            if (!ans.isEmpty()) {
                ans += " ";
            }
            ans += ans1;
        }

        if (ans.isEmpty()) {
            return "Zero";
        }

        return ans;
    }

    public static void main(String[] args) {
        Solution_1 solution_1 = new Solution_1();
        int number = 123456789;
        System.out.println(solution_1.numberToWords(number));
    }
}

