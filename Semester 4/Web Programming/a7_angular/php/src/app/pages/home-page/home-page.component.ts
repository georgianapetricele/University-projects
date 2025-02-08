import { Component,OnInit } from '@angular/core';
import { LogsService } from '../../services/logs.service';
import { Log } from '../../model/log';

@Component({
  selector: 'app-home-page',
  templateUrl: './home-page.component.html',
  styleUrl: './home-page.component.css'
})

export class HomePageComponent implements OnInit {

  logs: Log[] = [];
  pageCount = 0;
  page = 0;
  showNext = false;
  showPrevious = false;

  constructor(private logService: LogsService) {
   }

  ngOnInit(): void {
    console.log('ngOnInit called for homepage');
    this.getNumerOfPages();
  }

  getNumerOfPages(): void {
    this.logService.getAllLogs()
      .subscribe(logsRes => this.pageCount = Math.ceil(logsRes.length / 4));
  }

  loadTable(page = 1): void {
    this.logService.getLogsPaginated(4, page)
      .subscribe(logsRes => this.logs = logsRes);
      console.log(this.logs);
      console.log(this.logs.forEach(log => console.log(log.id)));
    this.page = page;
    this.showNext = false;
    this.showPrevious = false;
    if (this.pageCount > 0 && page < this.pageCount) {
      this.showNext = true;
    }
    if (page > 1) {
      this.showPrevious = true;
    }
  }

  goToPreviousPage(): void {
    if (this.page > 1) {
      this.loadTable(this.page - 1);
    }
  }

  goToNextPage(): void {
    if (this.page < this.pageCount) {
      this.loadTable(this.page + 1);
    }
  }

  public removeUser(): void {
    localStorage.setItem("username", "");
  }
}
