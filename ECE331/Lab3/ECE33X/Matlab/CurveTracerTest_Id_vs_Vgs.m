[Data,Setup]=Import_HP54600B_ScopeData;

Ids=Data(:,:,3)-Data(:,:,2);
Time=Data(:,:,1);
Vgs=Time*500;
plot(Vgs',Ids');
