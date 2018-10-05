AddAnimal_RemoveAnimal()
{

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

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

	lr_start_transaction("ClickAnimal");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_find("Text=Fish", 
		LAST);

	web_url("FISH", 
		"URL=https://jpetstore.cfapps.io/catalog/categories/FISH", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("ClickAnimal",LR_AUTO);

	lr_think_time(3);

	/* Selection du produit */

	lr_start_transaction("ClickProduct");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_find("Text=Angelfish", 
		LAST);

	web_reg_find("Text=FI-SW-01", 
		LAST);

	web_url("FI-SW-01", 
		"URL=https://jpetstore.cfapps.io/catalog/products/FI-SW-01", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog/categories/FISH", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("ClickProduct",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("ClickItem");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_find("Text=EST-1", 
		LAST);

	web_url("EST-1", 
		"URL=https://jpetstore.cfapps.io/catalog/items/EST-1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog/products/FI-SW-01", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("ClickItem",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("AddCart");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_find("Text=Shopping Cart", 
		LAST);

	web_url("Add to Cart", 
		"URL=https://jpetstore.cfapps.io/cart?add&itemId=EST-1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog/items/EST-1", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("AddCart",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("Remove");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_find("Text=Your cart is empty.", 
		LAST);

	web_url("Remove", 
		"URL=https://jpetstore.cfapps.io/cart?remove&itemId=EST-1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/cart", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("Remove",LR_AUTO);

	lr_think_time(3);

	return 0;
}