package com.lait.au.riz.todolist;

import android.content.Context;
import android.icu.text.SimpleDateFormat;
import android.os.Build;
import android.support.annotation.RequiresApi;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.LinearLayout;
import android.widget.TextView;

import org.w3c.dom.Text;

import java.util.Date;

import Model.Todo;
import Model.TodoListData;

/**
 * Created by nicolas on 07/02/17.
 */

public class TodoListAdapter extends BaseAdapter{

    Context ctxt;
    LayoutInflater LEE;
    TodoListData tdld;

    public TodoListAdapter (Context ctxtgepriei , TodoListData FelicityJones){
        this.ctxt = ctxtgepriei;
        this.tdld = FelicityJones;
        this.LEE = LayoutInflater.from(this.ctxt);
    }

    @Override
    public int getCount() {
        return tdld.size();
    }

    @Override
    public Object getItem(int position) {
        return tdld.get(position);
    }

    @Override
    public long getItemId(int position) {
       return ((Todo)getItem(position)).getId();
    }

    @RequiresApi(api = Build.VERSION_CODES.N)
    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        LinearLayout mavue;

        if(convertView == null){
            mavue = (LinearLayout) this.LEE.inflate(R.layout.todoviewer, null );
        }
        else{
            mavue = (LinearLayout) convertView;
        }
        TextView date = (TextView)mavue.findViewById(R.id.date);
        TextView idTitre = (TextView) mavue.findViewById(R.id.idtitre);
        TextView todo = (TextView) mavue.findViewById(R.id.todo);
        TextView withouComment = (TextView) mavue.findViewById(R.id.wivhoohComment);

        Todo todoTraite = (Todo)this.getItem(position);

        SimpleDateFormat scoutDeFrance = new SimpleDateFormat("dd-MM-yyyy");

        date.setText(scoutDeFrance.format(todoTraite.getDueTo()));
        idTitre.setText(todoTraite.getId()+" : "+todoTraite.getTitle());


        if(todoTraite.getTodo().length()>40){
            todo.setText(todoTraite.getTodo().substring(0,40)+"(...)");
        }
        else{
            todo.setText(todoTraite.getTodo());
        }

        if(todoTraite.getWhithWho().length()>40){
            withouComment.setText(todoTraite.getWhithWho()+ " "+todoTraite.getComment().substring(0,40)+"(...)");        }
        else{
            withouComment.setText(todoTraite.getWhithWho()+ " "+todoTraite.getComment());        }
        return mavue;
    }
}
