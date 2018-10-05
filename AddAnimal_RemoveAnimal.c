AddAnimal_RemoveAnimal()
{

	web_set_sockets_option("SSL_VERSION", "TLS1.2");
                      
	lr_start_transaction("Accueil");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_url("catalog", 
		"URL=https://jpetstore.cfapps.io/catalog", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("Accueil", LR_AUTO);

	lr_think_time(3);
	
	lr_start_transaction("ClickAnimal");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_find("Text={Category}", 
		LAST);
	
	//web_reg_save_param_ex("ParamName=ProductID", "<a href=\"/catalog/products/","\">", LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='FI-SW-01' 
Name ='ProductID' 
Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=ProductID",
		"LB/IC=products/",
		"RB/IC=\">",
		"NotFound=warning",
		"Ordinal=all",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/{Category}*",
		LAST);
		
	web_url("Animal",
		"URL=https://jpetstore.cfapps.io/catalog/categories/{Category}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://jpetstore.cfapps.io/catalog",
		"Snapshot=t14.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=/favicon.ico", ENDITEM,
		LAST);

	lr_end_transaction("ClickAnimal",LR_AUTO);
	
	lr_save_string(lr_paramarr_random("ProductID"), "randProduct");

	lr_think_time(3);

	/* Selection du produit */
	
	lr_start_transaction("ClickProduct");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_find("Text={randProduct}", 
		LAST);

/*Correlation comment: Automatic rules - Do not change!  
Original value='EST-1' 
Name ='itemId' 
Type ='Manual'*/
	web_reg_save_param_ex(
		"ParamName=itemId",
		"LB/IC=items/",
		"RB/IC=\">",
		"Ordinal=all",
		SEARCH_FILTERS,
		"Scope=Body",
		"RequestUrl=*/{randProduct}*",
		LAST);

	web_url("ProductID",
		"URL=https://jpetstore.cfapps.io/catalog/products/{randProduct}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=https://jpetstore.cfapps.io/catalog/categories/{Category}",
		"Snapshot=t15.inf",
		"Mode=HTML",
		EXTRARES,
		"URL=/favicon.ico", ENDITEM,
		LAST);

	lr_end_transaction("ClickProduct",LR_AUTO);
	
	//lr_save_string(lr_paramarr_random("itemId"), "randItem"); 
	
	lr_think_time(3);

	for (compteur=1; compteur<=(lr_paramarr_len("itemId")); compteur++)
	{
		lr_save_string(lr_paramarr_idx("itemId",compteur), "randItem");
		
		lr_start_transaction("ClickItem");
	
		web_reg_find("Text=JPetStore Demo", 
			LAST);
	
		web_reg_find("Text={randItem}", 
			LAST);
	
		web_url("ItemID",
			"URL=https://jpetstore.cfapps.io/catalog/items/{randItem}",
			"TargetFrame=",
			"Resource=0",
			"RecContentType=text/html",
			"Referer=https://jpetstore.cfapps.io/catalog/products/{randProduct}",
			"Snapshot=t16.inf",
			"Mode=HTML",
			EXTRARES,
			"URL=/favicon.ico", ENDITEM,
			LAST);
	
		lr_end_transaction("ClickItem",LR_AUTO);
	
		lr_think_time(3);
	
		lr_start_transaction("AddCart");
	
		web_reg_find("Text=JPetStore Demo", 
			LAST);
	
		web_reg_find("Text=Shopping Cart", 
			LAST);
	
		web_url("Add to Cart",
			"URL=https://jpetstore.cfapps.io/cart?add&itemId={randItem}",
			"TargetFrame=",
			"Resource=0",
			"RecContentType=text/html",
			"Referer=https://jpetstore.cfapps.io/catalog/items/{randItem}",
			"Snapshot=t17.inf",
			"Mode=HTML",
			EXTRARES,
			"URL=/favicon.ico", ENDITEM,
			LAST);
	
		lr_end_transaction("AddCart",LR_AUTO);
	
		lr_think_time(3);
	
		lr_start_transaction("Remove");
	
		web_reg_find("Text=JPetStore Demo", 
			LAST);
	
		web_reg_find("Text=Your cart is empty.", 
			LAST);
	
		web_url("Remove",
			"URL=https://jpetstore.cfapps.io/cart?remove&itemId={randItem}",
			"TargetFrame=",
			"Resource=0",
			"RecContentType=text/html",
			"Referer=https://jpetstore.cfapps.io/cart",
			"Snapshot=t18.inf",
			"Mode=HTML",
			EXTRARES,
			"URL=/favicon.ico", ENDITEM,
			LAST);
	
		lr_end_transaction("Remove",LR_AUTO);
	
		lr_think_time(3);
	}

	return 0;
}