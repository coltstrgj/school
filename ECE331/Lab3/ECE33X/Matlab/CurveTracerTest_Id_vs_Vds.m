[Data,Setup]=Import_HP54600B_ScopeData;

Ids=Data(:,:,3)-Data(:,:,2);
Time=Data(:,:,1);
Vds=Data(:,:,2);
plot(Vds',Ids');
title(Setup{1,1}{1}{1});
xlabel('Vds (V)');
ylabel('Id (A)');
