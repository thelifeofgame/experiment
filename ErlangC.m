function ErlangC 
clc;
pc=[];            
s=[];                                                    
m=[1 2 3 4 5 6 7 8 9 10 15 20 30 35 40 50 60 70 80 90 100];                           %��������������
L=length(m);

for i=1:L
    for a=1:100                                                %���뻰����ǿ��    
        if a<=m(i)
              for k=0:(m(i)-1)           
                  s=[s,a.^k/factorial(k)];
                  add=sum(s);
              end
              pc0=a.^m(i)/(a.^m(i)+factorial(m(i))*(1-a/m(i))*add);
              pc=[pc,pc0];               %���еȴ�����
              s=[];   
        end
    end
    x=1:length(pc);              %�����귶Χ   
    loglog(x,pc);                  %��������
    set(gca,'XGrid','on');         %��������
    set(gca,'XMinorTick','off');
    set(gca,'Xlim',[1 100]);      %�޶��������ȡֵ��Χ
    %set(gca,'XTick',[0.1 0.2 0.5 1 2 5 10 20 50 100]);           %x������̶�����
    %set(gca,'XMinorGrid','off');    
    set(gca,'Ylim',[0.01 1]);      %�޶��������ȡֵ��Χ
    set(gca,'YGrid','on');   
    %set(gca,'YMinorTick','off');
    hold on
    pc=[];
end
xlabel('������ǿ�Ȧ�(erl)','fontsize',8);
ylabel('���еȴ�����Pw','fontsize',8);

gtext('0.02');        %����y������ֵ
gtext('0.05');
gtext('0.2');
gtext('0.5');

gtext('m=4','fontsize',5);         %�������ͼ��������ע��
for i=2:L
    gtext(int2str(m(i)),'fontsize',5);
end

