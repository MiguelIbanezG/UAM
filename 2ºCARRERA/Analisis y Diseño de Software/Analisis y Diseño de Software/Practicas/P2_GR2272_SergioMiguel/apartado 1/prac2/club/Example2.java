package prac2.club;

public class Example2 {
    public static void main(String[] args) {
        Soccer premierLeague = new Soccer("premierLeague", 1924, true);
       
        Waterpolo barcelona92 = new Waterpolo("barcelona92", 1992, true, "Barcelona"); // true=nacional
        Waterpolo uam2006 = new Waterpolo("uam2006", 2006, false, "Cantoblanco"); // false=regional
       
        Padel padel1 = new Padel("padel1", 2000, true, "Cambridge"); // true=por parejas
        Padel padel2 = new Padel("padel2", 2010, false, "Granada"); // false=individual
       
        Section[] sections = { premierLeague, barcelona92, uam2006, padel1, padel2 };
        for (Section s : sections)
            System.out.println(s);
    }
}