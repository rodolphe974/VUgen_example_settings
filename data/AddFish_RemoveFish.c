AddFish_RemoveFish()
{

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_url("catalog", 
		"URL=https://jpetstore.cfapps.io/catalog", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_think_time(23);

	lr_start_transaction("ClickAnimal");

	web_image("sm_fish.gif", 
		"Src=/images/sm_fish.gif", 
		"Snapshot=t8.inf", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("ClickAnimal",LR_AUTO);

	lr_think_time(25);

	lr_start_transaction("ClickProduct");

	web_link("FI-SW-01", 
		"Text=FI-SW-01", 
		"Snapshot=t9.inf", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("ClickProduct",LR_AUTO);

	lr_think_time(13);

	lr_start_transaction("ClickItem");

	web_link("EST-1", 
		"Text=EST-1", 
		"Snapshot=t10.inf", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("ClickItem",LR_AUTO);

	lr_start_transaction("AddCart");

	web_link("Add to Cart", 
		"Text=Add to Cart", 
		"Snapshot=t11.inf", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("AddCart",LR_AUTO);

	lr_start_transaction("RemoveCart");

	web_link("Remove", 
		"Text=Remove", 
		"Snapshot=t12.inf", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("RemoveCart",LR_AUTO);

	return 0;
}