using System;

public class z19 {
    public static void Main() {
        DateTime date = DateTime.Parse( "1/1/1901" ); 

        int ret = 0;
        while ( date.Year <= 2000 ) 
        {
            if ( date.DayOfWeek == DayOfWeek.Sunday ) ++ret;
            date = date.AddMonths( 1 );
        }
        Console.WriteLine( "{0}", ret );
    }
}