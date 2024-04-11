new_system('Digital_PID_controller','Model');

add_block('built-in/SubSystem','Digital_PID_controller/PID_Controller');
add_block('simulink/Sources/In1','Digital_PID_controller/PID_Controller/Desired_signal');
add_block('simulink/Sources/In1','Digital_PID_controller/PID_Controller/Actual_Signal');

add_block('simulink/Commonly Used Blocks/Sum','Digital_PID_controller/PID_Controller/sum');
set_param('Digital_PID_controller/PID_Controller/sum','Inputs','+-');

add_block('simulink/Commonly Used Blocks/Gain','Digital_PID_controller/PID_Controller/P_controller_Gain');
add_block('simulink/Discrete/Unit Delay','Digital_PID_controller/PID_Controller/Unit Delay');
add_block('simulink/Commonly Used Blocks/Gain','Digital_PID_controller/PID_Controller/I_controller_Gain');
add_block('simulink/Commonly Used Blocks/Gain','Digital_PID_controller/PID_Controller/Sample_Time');

add_block('simulink/Commonly Used Blocks/Sum','Digital_PID_controller/PID_Controller/sum2');
set_param('Digital_PID_controller/PID_Controller/sum2','Inputs','-+');
add_block('simulink/Commonly Used Blocks/Gain','Digital_PID_controller/PID_Controller/D_controller_Gain');
add_block('simulink/Commonly Used Blocks/Gain','Digital_PID_controller/PID_Controller/Sample_Time_Recieprocal');

add_block('simulink/Commonly Used Blocks/Sum','Digital_PID_controller/PID_Controller/sum3');
set_param('Digital_PID_controller/PID_Controller/sum3','Inputs','++');

add_block('simulink/Discrete/Unit Delay','Digital_PID_controller/PID_Controller/Unit Delay2');
set_param('Digital_PID_controller/PID_Controller/Unit Delay2','orientation','left');

add_block('simulink/Commonly Used Blocks/Sum','Digital_PID_controller/PID_Controller/sum4');
set_param('Digital_PID_controller/PID_Controller/sum4','Inputs','+++');

add_block('simulink/Sinks/Out1','Digital_PID_controller/PID_Controller/Ctrl_Action');
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
add_line('Digital_PID_controller/PID_Controller','Desired_signal/1','sum/1','autorouting','smart');
add_line('Digital_PID_controller/PID_Controller','Actual_Signal/1','sum/2','autorouting','smart');

add_line('Digital_PID_controller/PID_Controller','sum/1','P_controller_Gain/1','autorouting','smart');
add_line('Digital_PID_controller/PID_Controller','sum/1','Unit Delay/1','autorouting','smart');
add_line('Digital_PID_controller/PID_Controller','sum/1','sum2/2','autorouting','smart');

add_line('Digital_PID_controller/PID_Controller','Unit Delay/1','I_controller_Gain/1','autorouting','smart');
add_line('Digital_PID_controller/PID_Controller','I_controller_Gain/1','Sample_Time/1','autorouting','smart');

add_line('Digital_PID_controller/PID_Controller','Sample_Time/1','sum3/1','autorouting','smart');
add_line('Digital_PID_controller/PID_Controller','sum3/1','Unit Delay2/1','autorouting','smart');
add_line('Digital_PID_controller/PID_Controller','Unit Delay2/1','sum3/2','autorouting','smart');

add_line('Digital_PID_controller/PID_Controller','Unit Delay/1','sum2/1','autorouting','smart');
add_line('Digital_PID_controller/PID_Controller','sum2/1','D_controller_Gain/1','autorouting','smart');
add_line('Digital_PID_controller/PID_Controller','D_controller_Gain/1','Sample_Time_Recieprocal/1','autorouting','smart');

add_line('Digital_PID_controller/PID_Controller','P_controller_Gain/1','sum4/1','autorouting','smart');
add_line('Digital_PID_controller/PID_Controller','sum3/1','sum4/2','autorouting','smart');
add_line('Digital_PID_controller/PID_Controller','Sample_Time_Recieprocal/1','sum4/3','autorouting','smart');

add_line('Digital_PID_controller/PID_Controller','sum4/1','Ctrl_Action/1','autorouting','smart');

set_param('Digital_PID_controller/PID_Controller/sum','IconShape','rectangular');
set_param('Digital_PID_controller/PID_Controller/sum2','IconShape','rectangular');
set_param('Digital_PID_controller/PID_Controller/sum3','IconShape','rectangular');
set_param('Digital_PID_controller/PID_Controller/sum4','IconShape','rectangular');


Blocks_with_Block_type = find_system('Digital_PID_controller','regexp','on','BlockType','.*');
Blocks_type = get_param(Blocks_with_Block_type,'BlockType');
for index = 1 : numel(Blocks_with_Block_type)
    switch Blocks_type{index}
        case 'Inport'
        case 'Outport'
            set_param(Blocks_with_Block_type{index},'ShowName','on');
        otherwise
            set_param(Blocks_with_Block_type{index},'ShowName','off');
    end
    switch Blocks_type{index}
        case 'Gain'
            set_param(Blocks_with_Block_type{index},'BackGroundColor','cyan');
        case 'UnitDelay'
            set_param(Blocks_with_Block_type{index},'BackGroundColor','Green');
        case 'Inport'
            set_param(Blocks_with_Block_type{index},'BackGroundColor','Red');
        case 'Outport'
            set_param(Blocks_with_Block_type{index},'BackGroundColor','Orange');
        case 'Sum'
            set_param(Blocks_with_Block_type{index},'BackGroundColor','Gray');
        case 'SubSystem'
            set_param(Blocks_with_Block_type{index},'BackGroundColor','Yellow');
    end
end
open_system('Digital_PID_controller');