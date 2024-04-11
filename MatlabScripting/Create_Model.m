function Create_Model(ModelName,Value_of_x)

add_block('built-in/SubSystem',[ModelName '/Multiply By ' num2str(Value_of_x)]);

set_param([ModelName ,'/Multiply By ' ,num2str(Value_of_x)],'Mask','on');
set_param([ModelName ,'/Multiply By ' ,num2str(Value_of_x)],'MaskDisplay',['disp(','"','multiply by ', num2str(Value_of_x),'"',')']);
set_param([ModelName ,'/Multiply By ' ,num2str(Value_of_x)],'MaskDescription','This Subsystem multiply by a fixed number');

add_block('simulink/Sources/In1',[ModelName '/Multiply By ' num2str(Value_of_x) '/InputNumber']);
add_block('built-in/Gain',[ModelName '/Multiply By ' num2str(Value_of_x) '/Gain']);
add_block('simulink/Sinks/Out1',[ModelName '/Multiply By ' num2str(Value_of_x) '/Result']);

add_line([ModelName '/Multiply By ' num2str(Value_of_x)] ,'InputNumber/1','Gain/1','autorouting','smart');
add_line([ModelName '/Multiply By ' num2str(Value_of_x)] ,'Gain/1','Result/1','autorouting','smart');

set_param([ModelName '/Multiply By ' num2str(Value_of_x) '/Gain'],'Gain',num2str(Value_of_x));
end