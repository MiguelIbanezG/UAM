package prac2.club;

public class Example1 {
    public static void main(String[] args) {
        Soccer teenager = new Soccer("teenager", 2005, false);
        
        Soccer premierLeague = new Soccer("premierLeague", 1924, true);
        
        Soccer women = new Soccer("women", 1993, false);
        
        Section[] sections = { teenager, premierLeague, women }; // se almacena en un array
        
        for (Section s : sections)
            System.out.println(s);
    }
}