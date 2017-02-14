package Model;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.List;

public class TodoListData {

    private ArrayList<Todo> internalTodoList;

    public TodoListData() {

        Calendar c = Calendar.getInstance();

        this.internalTodoList = new ArrayList<>();
        this.internalTodoList.add(new Todo("devoir 1", "Deposer le TP1 de CDAM deja en retard"));
        this.internalTodoList.add(new Todo("devoir 2", "Deposer le TP2 de CDAM deja en retard"));
        this.internalTodoList.add(new Todo("devoir 3", "Deposer le TP3 de CDAM, il est encore temps"));
        this.internalTodoList.add(new Todo("Courses", "Du lait, du beurre et des epinards"));
        this.internalTodoList.add(new Todo("Fete", "Organiser jeudi soir !! avant jeudi soir !!"));
        c.set(2017, 03, 10);
        this.internalTodoList.add(new Todo("devoir 4",
                "Deposer le TP4, il est encore temps", "My colleague", "", c
                .getTime()));

        c.set(2017, 3, 13);
        this.internalTodoList.add(new Todo("PJT", "Preparer rendu pjt",
                "My colleagues", "Ya du taf a faire\nFaut pas trainer",
                c.getTime()));
    }

    public int size() {
        return this.internalTodoList.size();
    }

    public Todo get(int position) {
        return this.internalTodoList.get(position);
    }

    public boolean add(Todo td) {
        return this.internalTodoList.add(td);
    }

    public void removeById(int id) {
		int taille = this.internalTodoList.size();
        for (int i = 0; i < taille; i++) {
            Todo d = this.internalTodoList.get(i);
            if (d.getId() == id) {
                this.internalTodoList.remove(d);
                return;
            }
        }
    }

    public List<Todo> getValuesAsNewList() {
        return new ArrayList<>(this.internalTodoList);
    }

}
