package Template;

import SortedList.SortedList;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Map;
import java.util.function.*;

import Strategy.Strategy;

public class Template<T extends Comparable<T>> {

  private List<TemplateUnit<T>> template = new ArrayList<>();
  private SortedList<T> obj = new SortedList<>();
  private Map<T, String> map = new LinkedHashMap<>();
  private List<Strategy<T>> strategys = new ArrayList<>();

  /**
   * Creates a template
   * 
   * @authors Sergio Hidalgo sergio.hidalgo@estudiante.uam.es
   *          Miguel Ibáñez miguel.ibannezg@estudiante.uam.es
   */
  public Template() {

  }

  /**
   * Adds a template unit
   * 
   * @param s string
   * @param o functions
   * @return the template
   */
  @SafeVarargs
  public final Template<T> add(String s, Function<? super T, ? extends Object>... o) {
    this.template.add(new TemplateUnit<T>(s, o));

    return this;
  }

  /**
   * Add an object list to the template
   * 
   * @param lst object list
   * @return the template
   */
  @SafeVarargs
  public final Template<T> addObjects(T... lst) {
    for (T i_T : lst) {

      this.obj.add(i_T);
    }

    this.obj.sort(Comparator.naturalOrder());
    return this;
  }

  /**
   * Add a sorting criteria to the template
   * 
   * @param b comparator to add
   * @return the template
   */
  public Template<T> withSortingCriteria(Comparator<T> b) {
    this.obj.addCriterion(b);
    return this;
  }

  /**
   * Emits the templates using a map, associating each object to the message
   * 
   * @return the map
   */
  public Map<T, String> emit() {

    String msg;
    for (T obj : this.obj) {
      msg = new String("");

      for (TemplateUnit<T> temp : this.template) {
        msg += temp.applyTemplate(obj);
      }
      
      
      for (Strategy<T> i_Strategy : this.strategys) {
        
        msg = i_Strategy.functStrategy(msg, obj);
      }

      this.map.put(obj, msg);

    }

    return this.map;

  }

  /**
   * Emits only the object "t"
   * 
   * @param t object to emit
   * @return the message
   */
  public String emit(T t) {

    String msg;
    msg = new String("");

    for (TemplateUnit<T> temp : this.template) {
      msg += temp.applyTemplate(t);

      this.map.put(t, msg);

    }

    return msg;
  }

  /**
   * Adds to the template using a condition
   * 
   * @param o condition
   * @param s message
   * @return the template
   */
  public Template<T> addWhen(Predicate<T> o, String s) {
    this.template.add(new TemplateUnit<T>(s, o));
    return this;
  }

  /**
   * Adds functions for each type <E> that its contained on <T>
   * 
   * @param <E> new type (subtipe of <T>)
   * @param o   function that gets the type <E> from <T>
   * @param s   message
   * @param o2  collection of functions
   * @return
   */
  @SafeVarargs
  public final <E extends Comparable<E>> Template<T> addForEach(Function<? super T, List<? extends E>> o,
      String s, Function<? super E, ? extends Object>... o2) {

    this.template.add(new TemplateEach<T, E>(o, s, o2));

    return this;
  }

  /**
   * This function ads the options to the array of Strategy
   * 
   * 
   * @param options
   */
  @SafeVarargs
  public final void withOptions(Strategy<T>... strategys) {
    this.strategys.addAll(List.of(strategys));
  }

}
