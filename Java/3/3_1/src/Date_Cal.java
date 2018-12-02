import java.util.Scanner;
import java.util.Date;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.temporal.ChronoUnit;

public class Date_Cal{
    public static void main(String[] args) throws ParseException{

        String year = "2017", month, day = "01";
        System.out.print("(1)Input the month: ");
        Scanner sc = new Scanner(System.in);
        int inp = sc.nextInt();
        if(inp < 10)
            month = "0"+inp;
        else
            month = inp + "";
        String date_str = year+month+day;
        getCalender(date_str);

        System.out.print("(2)Input the date(Format:yyyyMMdd): ");
        String date_strr = sc.next();
        getWeekday(date_strr);

        System.out.print("(3)"+"\nDate1(Format:yyyyMMdd): ");
        String d1 = sc.next();
        System.out.print("Date1(Format:yyyyMMDD): ");
        String d2 = sc.next();
        getGap(d1, d2);
    }

    public static void getCalender(String date_str) throws ParseException {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyyMMdd");//同字符串日期匹配格式
        System.out.println(" Su Mo Tu We Th Fr Sa");
        try {
            Date date_ = sdf.parse(date_str);//从字符串格式中解析日期
            Calendar cal = new GregorianCalendar();
            cal.setTime(date_);//设置当天日期

            //cal.set(Calendar.DATE, 1);
            int day = cal.get(Calendar.DATE);//该日期的day
            int first = cal.get(Calendar.DAY_OF_WEEK);//当天是本周第几天
            int last = cal.getActualMaximum(Calendar.DATE);//该月的最后一天是几号，相当月该月的天数

            for(int i = 1; i < first; i++)
            {
                System.out.print("   ");
            }
            for(int i = first; i <= 7; i++)
            {
                System.out.print("  "+(i-first+1));
            }
            System.out.println();

            for(int i = 9-first; i <= last; i++)
            {
                if(i < 10)
                    System.out.print("  "+i);
                else
                    System.out.print(" "+i);
                if((i+first-1)%7 == 0)
                    System.out.println();
            }
            System.out.println("\n");
        }catch (ParseException e) {
            e.printStackTrace();
        }
    }

    public static void getWeekday(String date_str) throws ParseException{
        SimpleDateFormat sdf = new SimpleDateFormat("yyyyMMdd");
        String[] weekdays= {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        try {
            Date date_ = sdf.parse(date_str);
            Calendar cal = new GregorianCalendar();
            cal.setTime(date_);

            System.out.println("It's " + weekdays[cal.get(Calendar.DAY_OF_WEEK) - 1]+"\n");
        }catch (ParseException e) {
            e.printStackTrace();
        }
    }

    public static void getGap (String d1, String d2) throws ParseException{
        SimpleDateFormat sdf = new SimpleDateFormat("yyyyMMdd");
        try {
            Date dt1 = sdf.parse(d1), dt2 = sdf.parse(d2);
            Calendar cal = Calendar.getInstance();
            cal.setTime(dt1);
            int day1 = cal.get(Calendar.DAY_OF_YEAR);
            cal.setTime(dt2);
            int day2 = cal.get(Calendar.DAY_OF_YEAR);
            long gap = Math.abs(ChronoUnit.DAYS.between(dt1.toInstant(), dt2.toInstant()));
            //System.out.println("The days between: "+(day2>day1?(day2-day1):(day1-day2)));
            System.out.println("The days between: "+gap);
        }catch (ParseException e) {
            e.printStackTrace();
        }
    }
}

