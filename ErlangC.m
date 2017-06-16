function ErlangC 
clc;
pc=[];            
s=[];                                                    
m=[1 2 3 4 5 6 7 8 9 10 15 20 30 35 40 50 60 70 80 90 100];                           %交换机出线容量
L=length(m);

for i=1:L
    for a=1:100                                                %流入话务量强度    
        if a<=m(i)
              for k=0:(m(i)-1)           
                  s=[s,a.^k/factorial(k)];
                  add=sum(s);
              end
              pc0=a.^m(i)/(a.^m(i)+factorial(m(i))*(1-a/m(i))*add);
              pc=[pc,pc0];               %呼叫等待概率
              s=[];   
        end
    end
    x=1:length(pc);              %横坐标范围   
    loglog(x,pc);                  %对数坐标
    set(gca,'XGrid','on');         %画网格线
    set(gca,'XMinorTick','off');
    set(gca,'Xlim',[1 100]);      %限定纵坐标的取值范围
    %set(gca,'XTick',[0.1 0.2 0.5 1 2 5 10 20 50 100]);           %x坐标轴刻度设置
    %set(gca,'XMinorGrid','off');    
    set(gca,'Ylim',[0.01 1]);      %限定纵坐标的取值范围
    set(gca,'YGrid','on');   
    %set(gca,'YMinorTick','off');
    hold on
    pc=[];
end
xlabel('话务量强度α(erl)','fontsize',8);
ylabel('呼叫等待概率Pw','fontsize',8);

gtext('0.02');        %输入y轴坐标值
gtext('0.05');
gtext('0.2');
gtext('0.5');

gtext('m=4','fontsize',5);         %用鼠标在图形上输入注释
for i=2:L
    gtext(int2str(m(i)),'fontsize',5);
end

