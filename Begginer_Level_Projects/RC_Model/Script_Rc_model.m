R = 1;
C = 1*10^-6;

model = gcs;

result = sim(model);

plot(result.logsout.get("Vc").Values);
xlabel("Time");
ylabel("Vc");
grid on;