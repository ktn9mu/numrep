import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

def forward_diff(f, t, h):
    return (f(t + h) - f(t)) / h

def central_diff(f, t, h):
    return (f(t + h) - f(t - h)) / (2 * h)

def extrapolated_diff(f, t, h):
    D1 = central_diff(f, t, h)
    D2 = central_diff(f, t, h/2)
    return (4*D2 - D1)/3

def rel_error(num, exact):
    return np.abs((num - exact) / exact)

functions = {
    "cos": (np.cos, lambda t: -np.sin(t)),
    "exp": (np.exp, np.exp)
}
methods = [
    ("Forward", forward_diff, 'tab:blue', '-'),
    ("Central", central_diff, 'tab:orange', '--'),
    ("Extrapolated", extrapolated_diff, 'tab:green', ':')
]
tvals = [0.1, 1.0, 100.0]
hvals = np.logspace(0, -16, 200)

for funcname, (f, df) in functions.items():
    fig, axes = plt.subplots(3, 2, figsize=(14, 12), sharex=True)
    for row, t in enumerate(tvals):
        exact = df(t)
        for mname, method, color, lstyle in methods:
            derivs = np.array([method(f, t, h) for h in hvals])
            relerrs = rel_error(derivs, exact)
            # Left: derivative
            axes[row, 0].plot(hvals, derivs, color=color, linestyle=lstyle, label=mname)
            # Right: relative error
            axes[row, 1].plot(hvals, relerrs, color=color, linestyle=lstyle, label=mname)
        axes[row, 0].set_xscale('log')
        axes[row, 1].set_xscale('log')
        axes[row, 1].set_yscale('log')
        axes[row, 0].set_ylabel(f"t = {t}\nNumerical Derivative")
        axes[row, 1].set_ylabel(f"t = {t}\nRelative Error")
        axes[row, 0].legend(fontsize=9)
        axes[row, 1].legend(fontsize=9)
        if row == 2:
            axes[row, 0].set_xlabel("h")
            axes[row, 1].set_xlabel("h")
        axes[row, 0].set_title(f"{funcname}(t={t}): Derivative")
        axes[row, 1].set_title(f"{funcname}(t={t}): Relative Error")
    plt.tight_layout()
    plt.savefig(f"{funcname}.png")
    plt.close()

