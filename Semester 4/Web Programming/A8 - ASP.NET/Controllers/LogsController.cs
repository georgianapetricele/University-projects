using lab10_webbb.Data;
using lab10_webbb.Models;
using lab10_webbb.Models.Entities;
using Microsoft.AspNetCore.Authorization;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;

namespace lab10_webbb.Controllers
{
    [Authorize]
    public class LogsController : Controller
    {
        private readonly ApplicationDbContext dbContext;
        public LogsController(ApplicationDbContext context)
        {
            this.dbContext = context;
        }


        [HttpGet]
        public IActionResult Add()
        {
            return View();
        }

        [HttpPost]
        public async Task<IActionResult> Add(AddLogViewModel viewModel)
        {
            var log = new LogReport
            {
                Type = viewModel.Type,
                Severity = viewModel.Severity,
                DateCreated = viewModel.DateCreated,
                //add the UserId of the current user that was logged in
                UserId = User.Identity.Name,
                Message = viewModel.Message
            };

            await dbContext.LogReports.AddAsync(log);
            await dbContext.SaveChangesAsync();
            return View();
        }

       /* [HttpGet]
        public async Task<IActionResult> List()
        {
            var logs = await dbContext.LogReports.ToListAsync();
            return View(logs);
        }*/

        [HttpGet]
        public async Task<IActionResult> Edit(int id)
        {
            var logReport = await dbContext.LogReports.FindAsync(id);
            return View(logReport);
        }

        [HttpPost]
        public async Task<IActionResult> Edit(LogReport updatedLog)
        {
            var log = await dbContext.LogReports.FindAsync(updatedLog.Id);
            if (log is not null)
            {
                log.Type = updatedLog.Type;
                log.Severity = updatedLog.Severity;
                log.DateCreated = updatedLog.DateCreated;
                log.Message = updatedLog.Message;

                await dbContext.SaveChangesAsync();
            }

            return RedirectToAction("List", "Logs");
        }

        [HttpGet]
        public async Task<IActionResult> List(string typeFilter, string severityFilter, int page = 1)
        {
            var query = dbContext.LogReports.AsQueryable();

            if (!string.IsNullOrEmpty(typeFilter))
            {
                query = query.Where(log => log.Type.Contains(typeFilter));
            }

            if (!string.IsNullOrEmpty(severityFilter))
            {
                query = query.Where(log => log.Severity.Contains(severityFilter));
            }

            var totalEntries = await query.CountAsync();
            var totalPages = (int)Math.Ceiling(totalEntries / (double)4);

            var entries = await query
                .OrderBy(e => e.Type)
                .Skip((page - 1) * 4)
                .Take(4)
                .ToListAsync();

            ViewBag.CurrentPage = page;
            ViewBag.TotalPages = totalPages;
            ViewBag.TypeFilter = typeFilter;
            ViewBag.SeverityFilter = severityFilter;

            return View(entries);
        }



        [HttpPost]
        public async Task<IActionResult> Delete(LogReport logToDelete)
        {
            var log = await dbContext.LogReports.FindAsync(logToDelete.Id);
            if (log is not null)
            {
                dbContext.LogReports.Remove(log);
                await dbContext.SaveChangesAsync();
            }

            return RedirectToAction("List", "Logs");
        }
    }
}
