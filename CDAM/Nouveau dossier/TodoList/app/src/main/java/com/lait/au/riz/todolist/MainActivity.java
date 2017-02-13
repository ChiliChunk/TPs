package com.lait.au.riz.todolist;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.util.ArrayList;

import Model.Todo;
import Model.TodoListData;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TodoListData maListData = new TodoListData();
        TodoListAdapter  tdla = new TodoListAdapter(this,maListData);
        ArrayList<Todo> maALTodo = (ArrayList) maListData.getValuesAsNewList();
//        ArrayAdapter<Todo> adapteer = new ArrayAdapter<Todo>(this , android.R.layout.simple_list_item_1 , maALTodo);
        ListView maLV = (ListView) findViewById(R.id.LV);
        maLV.setAdapter(tdla);
    }
}
