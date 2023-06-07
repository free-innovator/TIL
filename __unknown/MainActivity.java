package cookmanager.recipesaver;

import java.util.ArrayList;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;
import cookmanager.io.RecipeLoader;
import cookmanager.io.RecipeSaver;
import cookmanager.recipe.Page;
import cookmanager.recipe.Recipe;
import cookmanager.recipe.RecipeCategory;


public class MainActivity extends Activity {
	int pageIndex = 0;
	int recipeIndex = 0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        saveRecipe();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }
    
    public void prevPage(View view)
    {
    	if(!loadPage(recipeIndex, --pageIndex))
    		pageIndex++;
    }
    public void nextPage(View view)
    {
    	if(!loadPage(recipeIndex, ++pageIndex))
    		pageIndex--;
    }
    public void prevRecipe(View view)
    {
    	if(!loadPage(--recipeIndex, 0))
    		recipeIndex++;
    	else
    		pageIndex = 0;
    }
    public void nextRecipe(View view)
    {
    	if(!loadPage(++recipeIndex, 0))
    		recipeIndex--; 
    	else	
    		pageIndex = 0;
    }
    
    
    public void saveRecipe()
    {    	
    	RecipeSaver  rs = new RecipeSaver(this);
    	
    	/* 저장 */
    	ArrayList<Page> pList = new ArrayList<Page>();
    	pList.add(new Page("pict0_1", "text0_1", 40));
    	pList.add(new Page("pict0_2", "text0_2", 50));
    	pList.add(new Page("pict0_3", "text0_3", 60));
    	Recipe recipe = new Recipe("ddd", pList, RecipeCategory.LOW);    	
    	rs.saveRecipe(recipe);

    	Page[] pageList = new Page[5];
    	pageList[0] = new Page("pict1_1", "text1_1", 40);
    	pageList[1] = new Page("pict1_2", "text1_2", 50);
    	pageList[2] = new Page("pict1_3", "text1_3", 60);
    	pageList[3] = new Page("pict1_4", "text1_4", 70);
    	pageList[4] = new Page("pict1_5", "text1_5", 80);
    	recipe = new Recipe("efg", pageList, RecipeCategory.LOW);
    	rs.saveRecipe(recipe);
    	
    	pageList = new Page[4];
    	pageList[0] = new Page("pict2_1", "text2_1", 40);
    	pageList[1] = new Page("pict2_2", "text2_2", 50);
    	pageList[2] = new Page("pict2_3", "text2_3", 60);
    	pageList[3] = new Page("pict2_4", "text2_4", 70);
    	recipe = new Recipe("asdg", pageList, RecipeCategory.LOW);
    	rs.saveRecipe(recipe);
    	
    	loadPage(0, 0);
    }
    
    public boolean loadPage(int recipeIndex, int pageIndex)
    {
    	if(recipeIndex < 0 || pageIndex < 0) return false;    	
    	
    	RecipeLoader rl = new RecipeLoader(this);    	
    	Recipe[] recipeArray = rl.getRecipeArray(RecipeCategory.LOW, false);
    	
    	if(recipeIndex >= recipeArray.length) return false;
    	Recipe recipe = recipeArray[recipeIndex];
    	if(recipe == null) return false;
    	if(pageIndex >= recipe.getLength()) return false;
    	
    	Page page = recipe.getPage(pageIndex);
    	
    	TextView ridxText = (TextView)findViewById(R.id.recipe_name);
    	TextView pidxText = (TextView)findViewById(R.id.recipe_category);
    	TextView pictText = (TextView)findViewById(R.id.picture);
    	TextView textText = (TextView)findViewById(R.id.text);
    	TextView timeText = (TextView)findViewById(R.id.timeval);    	
    	
    	if(page != null)
    	{
    		ridxText.setText(recipe.getRecipeName());
    		pidxText.setText(recipe.getCategory().toString());
    		pictText.setText(page.getPictureAddress());
        	textText.setText(page.getText());
        	timeText.setText(String.valueOf(page.getTime()));
        	
        	return true;
    	}
    	return false;
    }
    
    public void test(View view)
    {    	
    	RecipeLoader rl = new RecipeLoader(this);
    	Recipe[] recipeArray = rl.getRecipeArray(RecipeCategory.LOW, true);
    	
    	recipeIndex = (recipeIndex+1)%recipeArray.length;
    	pageIndex = 0;
    	Recipe recipe = recipeArray[recipeIndex];
    	
    	TextView ridxText = (TextView)findViewById(R.id.recipe_name);
    	TextView pidxText = (TextView)findViewById(R.id.recipe_category);
    	TextView pictText = (TextView)findViewById(R.id.picture);
    	TextView textText = (TextView)findViewById(R.id.text);
    	TextView timeText = (TextView)findViewById(R.id.timeval);    	
    	
    	if(recipe != null)
    	{
    		ridxText.setText(recipe.getRecipeName());
    		pidxText.setText(recipe.getCategory().toString());
    		pictText.setText("NULL");
        	textText.setText("NULL");
        	timeText.setText("NULL");
    	}
    }
}