[Data,Setup]=Import_HP54600B_ScopeData;

Time=Data(:,:,1);
Vds=Data(:,:,2);
Vdd=Data(:,:,3);
Ids=Vdd-Vds;    % note Rd = 1 ohm

figure(1);
plot(Vds',Ids');
title(Setup{1,1}{1}{1});
xlabel('Vds (V)');
ylabel('Id (A)');
grid on;
legend({'Vgs=1V','Vgs=2V','Vgs=3V','Vgs=4V','Vgs=5V','Vgs=6V','Vgs=7V','Vgs=8V'});

figure(2);
plot(Time',Vds');
title('Vds (Channel 1)');
xlabel('Time (s)');
ylabel('Vds (A) [ch 1]');
grid on;
legend({'Vgs=1V','Vgs=2V','Vgs=3V','Vgs=4V','Vgs=5V','Vgs=6V','Vgs=7V','Vgs=8V'});

figure(3);
plot(Time',Vdd');
title('Vdd (Channel 2)');
xlabel('Time (s)');
ylabel('Vdd (A) [ch 2]');
grid on;
legend({'Vgs=1V','Vgs=2V','Vgs=3V','Vgs=4V','Vgs=5V','Vgs=6V','Vgs=7V','Vgs=8V'});

figure(4);
plot(Time',Ids');
title('Ids=(Vdd-Vds)/(R==1)');
xlabel('Time (s)');
ylabel('Ids (A) [ch2-ch1]');
grid on;
legend({'Vgs=1V','Vgs=2V','Vgs=3V','Vgs=4V','Vgs=5V','Vgs=6V','Vgs=7V','Vgs=8V'});

figure(5);
hold off;
plot(Time',Vds');
hold on;
plot(Time',Vdd');
title('Vds and Vdd (Channels 1 & 2)');
xlabel('Time (s)');
ylabel('Amps');
grid on;
legend({'Vgs=1V','Vgs=2V','Vgs=3V','Vgs=4V','Vgs=5V','Vgs=6V','Vgs=7V','Vgs=8V'});

